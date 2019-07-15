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
using namespace std;

#define ll	   long long
#define ull	  unsinged long long
#define vi	   vector<int>
#define vll	  vector<ll>
#define ii	   pair<int, int>
#define vii	  vector<pair<int, int> >
#define vs	   vector<string>
#define vd	   vector<double>
#define mii	   map<int, int>
#define mli	   map<ll, int>
#define msi	   map<string, int>

#define pb			  push_back
#define debug(x)		cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, a, b)	  for(int i=(a);i>=(b);i--)
#define pi			  acos(-1.0)
#define eps			 1e-6
#define mem(a, b)	   memset(a, b, sizeof(a))
#define inf			 1e9
//			 0123456789
const ll MOD = 1000000007;
const int MX = 300005;
vector<int> g[MX];
ll dis[MX];
int cas;
bool vis[MX];
ll fn[MX];
void cal(ll a, ll b, int k)
{
	fn[0] = a;
	fn[1] = b;
	for(int i = 2;i<=k;i++){
		fn[i] = (fn[i-1] + fn[i-2])%MOD;
	}
}
void goTo(int u, int d, int k)
{
	dis[u] = (dis[u] + fn[d])%MOD;
	vis[u] = 1;
	if(d==k) return;
	int s = g[u].size();
	for(int i = 0;i<s;i++){
		if(vis[g[u][i]]==0)
			goTo(g[u][i], d+1, k);
	}
}
void upd(int v, ll a, ll b, int k)
{
	mem(vis, 0);
	cal(a, b, k);
	goTo(v, 0, k);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		for(int i = 1;i<n;i++){
			dis[i] = 0LL;
			int u, v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dis[n] = 0LL;
		while(q--){
			int tp;
			cin>>tp;
			if(tp==1){
				int v, k, a, b;
				cin >> v >> k >> a >> b;
				upd(v, a, b, k);
			}
			else {
				int v;
				cin>>v;
				cout << dis[v] << "\n";
			}
		}
		for(int i = 1;i<=n;i++)
			g[i].clear();
	}
	return 0;
}

