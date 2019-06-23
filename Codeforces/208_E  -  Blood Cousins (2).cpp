/*=================================*\

	  Md. Shahidul Islam
		 CSE, BRUR
	  Rangpur, Bangladesh
 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English)
\*=================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 100005, lg = 17;
vi g[MAX];
int cnt[MAX], dep[MAX], siz[MAX];
int par[MAX][17], ans[MAX];
bool isBig[MAX];
vii queries[MAX];
void dfs_depth(int u)
{
    siz[u] = 1;
    for(auto v:g[u]){
        par[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs_depth(v);
        siz[u]+=siz[v];
    }
}
void add(int u, int val)
{
    cnt[dep[u]]+=val;
    for(auto v:g[u])
        if(!isBig[v]) add(v, val);
}
void dfs_cal(int u, bool big)
{
    int mx_cnt = -1, bigChild = -1;
    for(auto v:g[u])
        if(siz[v]>mx_cnt) mx_cnt = siz[v], bigChild = v;
    for(auto v:g[u])
        if(v!=bigChild) dfs_cal(v, 0);
    if(bigChild!=-1)
        isBig[bigChild] = 1, dfs_cal(bigChild, 1);
    add(u, +1);
    for(auto pp : queries[u])
        ans[pp.ss] = cnt[pp.ff] - 1;
    if(bigChild!=-1)
        isBig[bigChild] = 0;
    if(!big)
        add(u, -1);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin>>n;
    f(i, 1, n){
        cin>>p;
        g[p].pb(i);
    }
    dfs_depth(0);
    for(int i = 1;i<lg;i++)
        for(int v = 1; v<=n;v++)
            par[v][i] = par[par[v][i-1]][i-1];
    int q;
    cin>>q;
    for(int idx = 1; idx <= q; idx++){
        int v, h;
        cin >> v >> h;
        int d = dep[v];
        if(h<=dep[v]-1){
            for(int i=0; i<lg; i++)
                if(h & (1<<i))
                    v = par[v][i];
            queries[v].pb({d,idx});
        }
    }
    dfs_cal(0, 0);
    f(i, 1, q)
        cout << ans[i] << " ";
    return 0;
}
