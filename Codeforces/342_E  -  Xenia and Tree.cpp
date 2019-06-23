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

#define sI(a)		  scanf("%d", &a)
#define sL(a)		  scanf("%lld", &a)
#define sC(a)		  scanf("%c", &a)
#define sS(a)		  scanf("%s", a)
#define sF(a)		  scanf("%f", &a)
#define sD(a)		  scanf("%lf", &a)

#define sI2(a,b)	  scanf("%d %d", &a, &b)
#define sL2(a,b)	  scanf("%lld %lld", &a, &b)
#define sC2(a,b)	  scanf("%c %c", &a, &b)
#define sS2(a,b)	  scanf("%s %s", a, b)
#define sF2(a,b)	  scanf("%f %f", &a, &b)
#define sD2(a,b)	  scanf("%lf %lf", &a, &b)

#define sI3(a,b,c)	  scanf("%d %d %d", &a, &b, &c)
#define sL3(a,b,c)	  scanf("%lld %lld %lld", &a, &b, &c)
#define sC3(a,b,c)	  scanf("%c %c %c", &a, &b, &c)
#define sS3(a,b,c)	  scanf("%s %s %s", a, b, &c)
#define sF3(a,b,c)	  scanf("%f %f %f", &a, &b, &c)
#define sD3(a,b,c)	  scanf("%lf %lf %lf", &a, &b, &c)

#define pI(a)		  printf("%d", a)
#define pL(a)		  printf("%lld", a)
#define pC(a)		  printf("%c", a)
#define pS(a)		  printf("%s", a)
#define pF(a)		  printf("%f", a)
#define pNL		      printf("\n")

#define pI2(a,b)	  printf("%d %d", a, b)
#define pL2(a,b)	  printf("%lld %lld", a, b)
#define pC2(a,b)	  printf("%c %c", a, b)
#define pS2(a,b)	  printf("%s %s", a, b)
#define pF2(a,b)	  printf("%f %f", a, b)

#define pI3(a,b,c)	  printf("%d %d %d", a, b, c)
#define pL3(a,b,c)	  printf("%lld %lld %lld", a, b, c)
#define pC3(a,b,c)	  printf("%c %c %c", a, b, c)
#define pS3(a,b,c)	  printf("%s %s %s", a, b, c)
#define pF3(a,b,c)	  printf("%f %f %f", a, b, c)

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
const int MAX = 100001, mxL = 18;
vi adj[MAX];
int level[MAX], n, par[MAX][mxL];
int dis[MAX];
void dfs(int v, int p = 0)
{
	for(auto nxt:adj[v]) if(nxt!=p){
		level[nxt] = level[v] + 1;
		par[nxt][0] = v;
		dfs(nxt, v);
	}
}

void build_lca_table()
{
	for(int  L =  1;L<mxL;L++)
		for(int v = 1;v<MAX;v++)
			par[v][L] = par[par[v][L-1]][L-1];
}

int lca_of(int u, int v)
{
	if(level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];
	for(int L = 0;L<mxL;L++)
		if(d & (1<<L)) v = par[v][L];
	if(u==v)
		return u;
	for(int L = mxL-1;L>=0;L--)
		if(par[u][L]!=par[v][L])
			u = par[u][L], v = par[v][L];
	return par[u][0];
}
int distance_of(int u, int v)
{
	return level[u] + level[v] - 2*level[lca_of(u, v)];
}
queue<int> q;
vi in_queue;
void bfs()
{
	in_queue.clear();
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v:adj[u])if(dis[u]+1<dis[v]){
			dis[v] = dis[u]+1;
			q.push(v);
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, u, v;
	cin>>n>>m;
	for(int i = 1;i<n;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	
	build_lca_table();
	
	for(int i = 1;i<=n;i++)
		dis[i] = INT_MAX;
		
	dis[1] = 0;
	in_queue.pb(1);
	q.push(1);
	int sqt = sqrt(m);
	
	while(m--){
		int typ, v;
		cin>>typ>>v;
		if(typ==1){
			dis[v] = 0;
			in_queue.pb(v);
			q.push(v);
			if(in_queue.size()>sqt)
				bfs();
		}
		else{
			int ans = dis[v];
			for(int i = 0;i<in_queue.size();i++)
				ans = min(ans, distance_of(v, in_queue[i]));
			cout << ans << "\n";
		}
	}
	return 0;
}


