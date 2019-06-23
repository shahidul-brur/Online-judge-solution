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
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
const int maxn = (int)2e5+5;
const int LOGN = 20;
vi g[maxn];
int a[maxn];
ll w[maxn][LOGN];
int ans[maxn], par[maxn][LOGN];
void dfs(int u)
{
    for(int v:g[u]){
        dfs(v);
        ans[u]+=ans[v];
    }
}
int n;
void initLCA()
{
    for(int i=1;i<LOGN;i++){
        for(int v=1;v<=n;v++){
            par[v][i] = par[par[v][i-1]][i-1];
            w[v][i]= w[v][i-1] + w[par[v][i-1]][i-1];
        }
    }
    
    for(int v=1;v<=n;v++){
        int wt = a[v];
        int node = v;
        for(int i=LOGN-1;i>=0;i--) if(par[node][i]>0 && w[node][i]<=wt){
            wt-=w[node][i];
            node = par[node][i];
            if(wt<=0 || node<=1) break;
        }
        ans[v]++;
        ans[par[node][0]]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int u;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        cin>>u>>w[i][0];
        g[u].pb(i);
        par[i][0] = u;
    }
    initLCA();
    dfs(1);
    for(int i=1;i<=n;i++) cout << ans[i]-1 << " ";
    return 0;
}
