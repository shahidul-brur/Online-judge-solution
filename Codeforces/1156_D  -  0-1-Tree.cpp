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
const int maxn = 200002, inf = 1e8;
bool del[maxn];
vi g[maxn], w[maxn];
int sub[maxn],tot;
long long ans,cnt[2][2];
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
void update(int u, int p, int b, int e, int typ)
{
    if(typ==1) cnt[b][e]++;
    else{
        ans++;
        if(b==0 && e==0){
            ans++;
            ans+=cnt[0][0]*2;
            ans+=cnt[0][1];
            ans+=cnt[1][1];
        }
        else if(b==0 && e==1){
            ans+=cnt[0][0];
        }
        else if(b==1 && e==0){
            ans+=cnt[1][1];
        }
        else if(b==1 && e==1){
            ans++;
            ans+=cnt[1][1]*2;
            ans+=cnt[1][0];
            ans+=cnt[0][0];
        }
    }
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        int cur = w[u][i];
        if(v==p || del[v] || (e>b && cur<e) || (e<b && cur>e)) continue;
        update(v,u,b,cur,typ);
    }
}

void decompose(int u)
{
    dfs_subsz(u,u);
    tot=sub[u];
    int cen = centroid(u,u);
    del[cen]=1;
    for(int i=0;i<g[cen].size();i++) {
        int v = g[cen][i];
        if(del[v]) continue;
        update(v,cen,w[cen][i],w[cen][i],0); // calculate
        update(v,cen,w[cen][i],w[cen][i],1); // update
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
    int n,u,v,wgt;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v>>wgt;
        g[u].push_back(v), g[v].push_back(u);
        w[u].push_back(wgt), w[v].push_back(wgt);
    }
    decompose(1);
    cout << ans << "\n";
    return 0;
}

