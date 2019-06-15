//Accepted

#include <bits/stdc++.h>
using namespace std;
int parent[5000];
vector< int > g[5000];
int vis[5000];
map<string, int> si; //string to int
map<int , string> is; //int to string
int source, dest, s;
void bfs()
{
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }
    }

}
int main()
{
    freopen("762.txt", "r", stdin);
    int n, i, t=1, j, order[5000], k;
    string from, to;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0, s=0;i<n;i++)
        {
            cin>>from>>to;
            if(si.find(from)==si.end())
            {
                si[from]=s;
                is[s]=from;
                s++;
            }
            if(si.find(to)==si.end())
            {
                si[to]=s;
                is[s]=to;
                s++;
            }
            g[si[from]].push_back(si[to]);
            g[si[to]].push_back(si[from]);
        }
        cin>>from>>to;

        if(t>1)
            cout<<'\n';
        if(from.compare(to)==0)
            cout<<from<<" "<<to<<'\n';
        else if(si.find(to)==si.end() || si.find(to)==si.end())
            cout<<"No route"<<'\n';
        else
        {
            source=si[from];
            dest=si[to];
            memset(vis, 0, sizeof(vis));
            bfs();
            if(vis[dest]==0)
                cout<<"No route"<<'\n';
            else
            {
                i=dest;k=0;
                for(;;)
                {
                    order[k++]=i;
                    if(i==source)
                        break;
                    i=parent[i];
                }
                for(i=k-1;i>0;i--)
                    cout<<is[order[i]]<<" "<<is[order[i-1]]<<'\n';
            }
        }
        for(i=0;i<s;i++)
            g[i].resize(0);
        is.clear();
        si.clear();
        t++;
    }
    return 0;
}

