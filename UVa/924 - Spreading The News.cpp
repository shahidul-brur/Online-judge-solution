//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[2503];
int f[2502], source, day, maxi, vis[2502];
void bfs()
{
    queue<int> q;
    int reach,d,i,j,r;
    vis[source]=1;
    maxi=d=day=0;
    q.push(source);
    r=1;
    while(!q.empty())
    {
        reach=0;
        for(j=0;j<r;j++)
        {
            int u=q.front();
            q.pop();
            for(i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(vis[v]==0)
                {
                    vis[v]=1;
                    reach++;
                    q.push(v);
                }
            }
        }
        d++;
        r=reach;
        if(reach>maxi)
        {
            maxi=reach;
            day=d;
        }
    }
}
int main()
{
    freopen("924.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, M, N, n=0, path[5000], p, j, t, cas=1;
    cin>>M;
    for(i=0;i<M;i++)
    {
        cin>>f[i];
        for(j=0;j<f[i];j++)
        {
            cin>>p;
            g[i].push_back(p);
        }
    }

    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>source;
        memset(vis, 0, sizeof(vis));
        bfs();

        if(maxi==0)
            printf("0\n");
        else printf("%d %d\n", maxi, day);

    }
    return 0;
}
