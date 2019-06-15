#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef pair<int, pii> piii;

#define pb push_back


vector<piii> EdgeList;

class disjointSet
{
    private:
        int ranks[2004], parent[2004];
    
    public:
        disjointSet(int node)
        {
            for(int i=0;i<=node;i++)
            {
                ranks[i]=0;
                parent[i]=i;
            }
        }
        
        int findSet(int x)
        {
            return (parent[x]==x ? x: parent[x]=findSet(parent[x]));
        }
        
        bool isSameSet(int a, int b)
        {
            return (findSet(a)==findSet(b));
        }
        
        void setUnion(int a, int b)
        {
            int x = findSet(a);
            int y = findSet(b);
            
            if(!isSameSet(x, y))
            {
                if(ranks[x]>ranks[y])
                    parent[y] = x;
                else
                {
                    parent[x] = y;
                    if(ranks[x]==ranks[y])
                        ranks[y]++;
                }
            }
        }
};

int kruskal(int node, int edge)
{
    disjointSet dSet(node);
    sort(EdgeList.begin(), EdgeList.end());
    
    int cost=0;
    for(int i=0;i<edge;i++)
    {
        if(!dSet.isSameSet(EdgeList[i].second.first, EdgeList[i].second.second))
        {
            cost+=EdgeList[i].first;
            dSet.setUnion(EdgeList[i].second.first, EdgeList[i].second.second);
        }
    }
    return cost;
}
int main()
{
    int node, i, j, test, u, v, w, mstCost, edge, id, cas=1;
    map<string, int> mapper;
    string city1, city2;
    cin>>test;
    while(test--)
    {
        cin>>node;
        if(node>0)
            cin>>edge;
        
        if(cas>1)
            cout<< "\n";
        
        if(node==0 || edge==0)
            cout<< "0" << "\n";
        else
        {
            id=0;
            for(i=0;i<edge;i++)
            {
                cin>>city1>>city2>>w;
                if(mapper.find(city1)==mapper.end())
                    mapper[city1]=id++;
                if(mapper.find(city2)==mapper.end())
                    mapper[city2]=id++;
                
                u=mapper[city1];
                v=mapper[city2];
                EdgeList.pb(piii(w, pii(u, v)));
            }
            mstCost = kruskal(node, edge);
            
            cout<< mstCost << "\n";
            EdgeList.clear();
            mapper.clear();
        }
        cas++;
    }
    return 0;
}
