#include <bits/stdc++.h>
using namespace std;
vector<int> G[102], order;
vector<string> wine;
int vis[102], n;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        if(vis[G[u][i]]==0)
            dfs(G[u][i]);
    }
    order.push_back(u);
}
int main()
{
    freopen("11060.txt", "r", stdin);
    int c=1, m, i, j, b, a;
    string s1, s2;
    map<string, int> mapper;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin>>s1;
            vis[i]=0;
            wine.push_back(s1);
        }
        sort(wine.begin(), wine.end());
        for(i=0;i<n;i++)
        {
            mapper[wine[i]]=i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            G[mapper[s2]].push_back(mapper[s1]);
        }
        for(i=0;i<n;i++)
        {
            sort(G[i].begin(), G[i].end());
        }
        for(i=0;i<n;i++)
            if(vis[i]==0)
                dfs(i);
                
        printf("Case #%d: Dilbert should drink beverages in this order:",c);
        for(i=0;i<n;i++)
            cout<< " " << wine[order[i]];
        printf(".\n\n");
        for(i=0;i<n;i++)
            G[i].clear();
        mapper.clear();
        order.clear();
        wine.clear();
        c++;
    }
    return 0;
}
