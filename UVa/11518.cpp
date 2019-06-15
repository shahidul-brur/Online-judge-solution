//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> Graph[10002];
bool vis[10002];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<Graph[u].size();i++)
    {
        int v=Graph[u][i];
        if(!vis[v])
            dfs(v);
    }
}
int main()
{
    //freopen("11518.txt", "r", stdin);
    int t, n, m, l, i, a, b, cnt;
    int x[10002], fallen[10002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &l);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d", &a, &b);
            Graph[a].push_back(b);
        }
        for(i=1;i<=n;i++)
            vis[i]=0;
        for(i=1;i<=l;i++)
        {
            scanf("%d", &a);
            if(!vis[a])
                dfs(a);
        }
        cnt=0;
        for(i=1;i<=n;i++)
            if(vis[i])
                cnt++;
        printf("%d\n",cnt);
        for(i=0;i<=n;i++)
            Graph[i].resize(0);
    }
    return 0;
}
