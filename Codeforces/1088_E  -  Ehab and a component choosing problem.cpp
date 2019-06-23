#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300002;
vector<int> g[maxn];
int n, a[maxn], k;
ll dp[maxn], mx;
void dfs(int u, int p){
    dp[u] = a[u];
    for(int v:g[u]) if(v!=p){
        dfs(v,u);
        dp[u] += max(dp[v], 0LL);
    }
    mx = max(mx, dp[u]);
}
void dfs2(int u, int p){
    dp[u] = a[u];
    for(int v:g[u]) if(v!=p){
        dfs2(v, u);
        dp[u] += max(dp[v], 0LL);
    }
    if(dp[u]==mx){
        dp[u] = 0LL;
        ++k;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v; 
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mx = INT_MIN;
    dfs(1,0);
    k = 0;
    dfs2(1,0);
    cout << mx*k << " " << k;
    return 0;
}