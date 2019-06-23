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
const int MAX = 100002;
vi g[MAX];
int cnt[MAX], mx_cnt, col[MAX], siz[MAX];
ll sum, ans[MAX];
bool isBig[MAX];
void dfs_siz(int v, int p)
{
	siz[v] = 1;
	for(int u:g[v]){
		if(u!=p){
			dfs_siz(u, v);
			siz[v]+=siz[u];
		}
	}
}
void inc(int v, int p)
{
	cnt[col[v]]++;
	if(cnt[col[v]]>mx_cnt){
		mx_cnt = cnt[col[v]];
		sum = col[v];
	}
	else if(cnt[col[v]]==mx_cnt){
		sum += col[v];
	}
	for(int u:g[v]){
		if(u!=p && !isBig[u])
			inc(u, v);
	}
}
void dec(int v, int p)
{
	if(cnt[col[v]]== mx_cnt){
		sum-=col[v];
	}
	cnt[col[v]]--;
	for(int u:g[v]){
		if(u!=p && !isBig[u])
			dec(u, v);
	}
}
void dfs_cal(int v, int p, bool Big)
{
	int mx_sz = -1, bigChild = -1;
	for(int u:g[v]){
		if(u!=p && siz[u]>mx_sz){
			mx_sz = siz[u];
			bigChild = u;
		}
	}
	for(int u:g[v]){
		if(u!=p && u!=bigChild){
			dfs_cal(u, v, 0);
		}
	}
	if(bigChild!=-1)
		dfs_cal(bigChild, v, 1), isBig[bigChild] = 1;
	inc(v, p);
	ans[v] = sum;
	if(bigChild!=-1)
		isBig[bigChild] = 0;
	if(!Big){
		dec(v, p);
		mx_cnt = 0;
		sum = 0;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>col[i];
	for(int i = 1;i<n;i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs_siz(1, 0);
	dfs_cal(1, 0, 0);
	f(i, 1, n)
		cout << ans[i] << " ";
	return 0;
}


