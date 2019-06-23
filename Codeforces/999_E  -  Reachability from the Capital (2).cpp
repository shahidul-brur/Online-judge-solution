#include<bits/stdc++.h>
using namespace std;
vector<int> g[5002], rg[5002];
bool vis[5002];
int in[5002];
void dfs(int u)
{
    vis[u]=1;
    //cout << u << " !!\n";
    for(int v:g[u]) if(!vis[v])
        dfs(v);
}
stack<int> stk;
void dfs2(int u)
{
    vis[u]=1;
    //cout << u << " #\n";
    for(int v:g[u]) if(!vis[v])
        dfs(v);
    stk.push(u);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, e, s;
    cin>>n>>e>>s;
    for(int i = 1;i<=e;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
        in[v]++;
    }
    dfs(s);
    int cnt = 0;
    /*
    for(int i = 1;i<=n;i++)
    {
        if(in[i]==0 && vis[i]==0)
        {
            cnt++;
            cout << i << ";\n========\n";
            dfs(i);
        }
    }
    */
    for(int i = 1;i<=n;i++) if(vis[i]==0)
    {
       // cout << i << ",\n------------\n";
        //cnt++;
        dfs2(i);
    }
    memset(vis, 0, sizeof vis);
    while(!stk.empty())
    {
        int u = stk.top(); stk.pop();
        if(!vis[u])
        {
            cnt++;
            //cout << u << "..\n";
            dfs(u);
        }
    }
    cout << cnt;
    return 0;
}

