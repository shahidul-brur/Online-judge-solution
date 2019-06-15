 //Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[100002];
int f[100002], source, dest, d[100002];
void bfs()
{
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]==0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    //freopen("1148.txt", "r", stdin);
    int i, M, N, t, cas=1, level, j, p;
    scanf("%d", &t);
    while(t--)
    {
        cin>>M;
        for(i=0;i<M;i++)
        {
            cin>>level;
            cin>>f[level];
            for(j=0;j<f[level];j++)
            {
                cin>>p;
                g[level].push_back(p);
            }
        }
        memset(d, 0, sizeof(d));
        cin>>source>>dest;
        bfs();
        if(cas>1)
            printf("\n");
        printf("%d %d %d\n", source, dest, d[dest]-1);
        for(i=0;i<=M;i++)
            g[i].resize(0);
        cas++;
    }
    return 0;
}
