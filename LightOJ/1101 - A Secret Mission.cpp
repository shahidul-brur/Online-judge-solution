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
#include<stdio.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 16;
vi g[maxn];
vi c[maxn];
int par[maxn], nodes[maxn];
int findPar(int u)
{
	return (par[u]==u?u:(par[u]=findPar(par[u])));
}
struct edge{
	int u, v, w;
	bool operator< (const edge &o) const{
		return w<o.w;
	}
}e[maxn];
int n,m;
void unite(int eid){
	int u=findPar(e[eid].u);
	int v=findPar(e[eid].v);
	if(u==v) return;
	if(nodes[u]<nodes[v]){
		par[u] = v;
		nodes[v]+=nodes[u];
	}
	else{
		par[v] = u;
		nodes[u]+=nodes[v];
	}
	g[u].pb(v); c[u].pb(e[eid].w);
	g[v].pb(u); c[v].pb(e[eid].w);
}
int lev[maxn], treePar[maxn][LOGN+2], dis[maxn][LOGN+2];
void dfs(int u, int p=0)
{
	treePar[u][0] = p;
	lev[u] = lev[p] + 1;
	int siz = g[u].size();
	f0(i,siz) if(g[u][i]!=p)
	{
		dis[g[u][i]][0] = c[u][i];
		dfs(g[u][i], u);
	}
}
void buildLCA(){
	f1(d,LOGN){
		f1(v,n){
			int p = treePar[v][d-1];
			treePar[v][d] = treePar[p][d-1];
			dis[v][d] = max(dis[v][d-1], dis[p][d-1]);
		}
	}
}
int query(int loV, int upV){
	if(lev[loV]<lev[upV]) swap(loV,upV);
	int ans = 0;
	int d = lev[loV] - lev[upV];
	f0(i,LOGN) if((1<<i) & d){
		ans = max(ans, dis[loV][i]);
		loV = treePar[loV][i];
	}
	if(loV==upV) return ans;
	fr(i,LOGN,0){
		if(treePar[loV][i]!=treePar[upV][i]){
			ans = max(ans, dis[loV][i]);
			ans = max(ans, dis[upV][i]);
			loV = treePar[loV][i], upV = treePar[upV][i];
		}
	}
	ans = max(ans, dis[loV][0]);
	ans = max(ans, dis[upV][0]);
	return ans;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    f1(cas,t)
    {
    	scanf("%d %d", &n, &m);
    	f0(i,m) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
  		sort(e, e+m);
  		f1(i,n) par[i]=i, nodes[i]=1;
  		f0(i,m) unite(i);
  		mem(dis,0);
  		dfs(1,0);
  		//cout << "hi\n";
  		buildLCA();
  		// f1(i,n)
  		// {
  		// 	f0(j,4){
  		// 		cout << i << ", "<< j << " : " << dis[i][j] << "\n";
  		// 	}
  		// }
    	int q;
    	scanf("%d", &q);
    	printf("Case %d:\n", cas);
    	while(q--)
    	{
    		int s, t;
    		scanf("%d %d", &s, &t);
    		printf("%d\n", query(s,t));
    	}
    	f1(i,n) g[i].clear();
    	f1(i,n) c[i].clear();
    }
    return 0;
}
