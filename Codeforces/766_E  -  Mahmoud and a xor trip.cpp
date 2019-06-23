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
const int maxn = 100002;
bool del[maxn];
vi g[maxn], w[maxn];
int sub[maxn],tot,a[maxn],cen;
long long ans,cnt[22][2];
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
    int cur = a[cen]^d;
    if(typ==0)
        ans+=cur;
    for(int i=0;i<=20;i++){
        int b,c;
        if(d&(1<<i)) b=1;
        else b=0;
        if(cur&(1<<i)) c=1;
        else c=0;
        if(typ==1) cnt[i][b]++;
        else {
            ans+=(1<<i)*1LL*cnt[i][c^1];
        }
    }
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==p || del[v]) continue;
        update(v,u,d^a[v],typ);
    }
}

void decompose(int u)
{
    dfs_subsz(u,u);
    tot=sub[u];
    cen = centroid(u,u);
    del[cen]=1;
    for(int i=0;i<g[cen].size();i++) {
        int v = g[cen][i];
        if(del[v]) continue;
        update(v,cen,a[v],0); // calculate
        update(v,cen,a[v],1); // update
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
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i], ans+=a[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    decompose(1);
    cout << ans << "\n";
    return 0;
}


