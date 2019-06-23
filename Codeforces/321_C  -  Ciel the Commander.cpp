#include<bits/stdc++.h>
using  namespace std;
const int mxn = (int)1e5+2;
set<int> adj[mxn];
int depth[mxn], siz[mxn], tot_sz, level[mxn];
void dfs(int u, int p)
{
    for(int v:adj[u])
    {
        if(v==p) continue;
        depth[v] = depth[u]+1;
        dfs(v, u);
    }
}
void cal_sub(int u, int p)
{
    siz[u] = 1;
    tot_sz++;
    for(int v:adj[u])
    {
        if(v==p) continue;
        cal_sub(v, u);
        siz[u] += siz[v];
    }
}
int find_centroid(int u, int p)
{
    for(int v:adj[u])
        if(v!=p && siz[v]>tot_sz/2) 
            return find_centroid(v, u);
    return u;
}
void decompose(int u, int p, int d)
{
    tot_sz = 0;
    cal_sub(u, u);
    int centroid = find_centroid(u, u);
    level[centroid] = d;
    for(int v:adj[centroid])
    {
        adj[v].erase(centroid);
        decompose(v, centroid, d+1);
    }
    adj[centroid].clear();
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<n;i++)
    {
        int u, v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1, 0);
    decompose(1, 0, 0);
    for(int i = 1;i<=n;i++)
        cout << (char)('A'+level[i]) << " ";
    return 0;
}
