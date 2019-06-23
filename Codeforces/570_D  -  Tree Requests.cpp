#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int maxn = 500005;
vi g[maxn];
int cnt[maxn][27], siz[maxn], dep[maxn], ans[maxn];
vector<pair<int, int> > Q[maxn];
int col[maxn], odd[maxn];
bool isBig[maxn];
void dfs_subsz(int u, int p, int d)
{
    dep[u] = d;
    siz[u] = 1;
    for(int v : g[u]){
        if(v!=p) dfs_subsz(v, u, d+1);
        siz[u]+=siz[v];
    }
}
void add(int u, int p)
{
    cnt[dep[u]][col[u]]^=1;
    if(cnt[dep[u]][col[u]]==1)
        odd[dep[u]]++;
    else odd[dep[u]]--;
    for(int v:g[u]){
        if(v!=p && !isBig[v])
            add(v, u);
    }
}
void dfs_cal(int u, int p, bool Big)
{
    int mx_sz = -1, bigChild = -1;
    for(int v:g[u]){
        if(v!=p && siz[v]>mx_sz)
            mx_sz = siz[v], bigChild = v;
    }
    for(int v:g[u]){
        if(v!=p && v!=bigChild)
            dfs_cal(v, u, 0);
    }
    if(bigChild!=-1)
        isBig[bigChild] = 1, dfs_cal(bigChild, u, 1);
    add(u, p);
    for(auto pr: Q[u]){
        ans[pr.second] = (odd[pr.first]<=1);
    }
    if(bigChild!=-1)
        isBig[bigChild] = 0;
    if(!Big)
        add(u, p);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        col[i+1] = s[i] - 'a' + 1;
    }
    for(int i=1;i<=q;i++){
        int v, h;
        cin>>v>>h;
        Q[v].push_back({h, i});
    }
    dfs_subsz(1, 1, 1);
    dfs_cal(1, 1, 0);
    for(int i=1;i<=q;i++)
        if(ans[i])
            cout << "Yes\n";
        else cout << "No\n";
    return 0;
}
