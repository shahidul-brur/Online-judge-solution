//Accepted

#include <bits/stdc++.h>
using namespace std;
vector <int> edge[302];
int color[302], visited[302], n, bicolor;
void doColor()
{
    queue<int> q;
    for(int i=0; i<n;i++)
        color[i]=0, visited[i]=0;

    q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0; i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(color[u]==1 && color[v]==1)
            {
                bicolor=0;
                break;
            }
            if(color[u]==0 && visited[v]==0)
            {
                color[v]=1;
                visited[v]=1;
            }
            q.push(v);
        }
        if(bicolor==0)
            break;
    }
}
int main()
{
    //freopen("10004.txt", "r", stdin);
    int ed, i, j, a, b;
    while(cin>>n)
    {
        if(n==0)
            break;
        cin>>ed;
        while(ed--)
        {
            cin>>a>>b;
            if(a<b)
                edge[a].push_back(b);
            else
                edge[b].push_back(a);
        }
        bicolor=1;
        doColor();
        if(bicolor==1)
            cout<<"BICOLORABLE."<<'\n';
        else cout<<"NOT BICOLORABLE."<<'\n';
        for(i=0;i<n;i++)
            edge[i].resize(0);
    }
    return 0;
}
