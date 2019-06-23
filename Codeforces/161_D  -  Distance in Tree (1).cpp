/*==============================================*\
ID:          shahidul_brur

Name:     Md. Shahidul Islam
Study:      CSE, BRUR
Address:  Rangpur, Bangladesh

 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English)
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef vector<int> vi;
const int MOD = (int)1e9+7;
const int maxn = 50002, inf = 1e8;
bool del[maxn];
vi g[maxn];
int sub[maxn],tot,k;
long long ans;
int cnt[502];
void dfs_subsz(int u, int p){
    sub[u]=1;
    for(int v:g[u]) if(v!=p && !del[v])
        dfs_subsz(v,u), sub[u]+=sub[v];
}
int centroid(int u, int p){
    for(int v:g[u]) if(v!=p && !del[v] && sub[v]>tot/2)
        return centroid(v,u);
    return u;
}
void update(int u, int p, int d, int typ)
{
    if(d>k) return;
    if(typ==1)cnt[d]++;
    else ans+=cnt[k-d];
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==p || del[v]) continue;
        update(v,u,d+1,typ);
    }
}

void decompose(int u)
{
    dfs_subsz(u,u);
    tot=sub[u];
    int cen = centroid(u,u);
    del[cen]=1;
    cnt[0] = 1;
    for(int i=0;i<g[cen].size();i++) {
        int v = g[cen][i];
        if(del[v]) continue;
        update(v,cen,1,0); // calculate
        update(v,cen,1,1); // update
    }
    memset(cnt,0, sizeof(cnt));
    for(int v:g[cen]) if(!del[v])
        decompose(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,u,v;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    decompose(1);
    cout << ans << "\n";
    return 0;
}

