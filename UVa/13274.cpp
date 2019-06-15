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
#define mod			 1000000007
#define inf			 1e9
//			 0123456789

const int MX = 1005;
int dp[MX];
vi g[MX];
int k;

void dfs(int u, int p)
{
	int s = g[u].size();
	dp[u] = 1;
	if(s==1) return;
	vector<int> siz;
	f(i, 0, s-1)
	{
		int v = g[u][i];
		if(v!=p)
		{
			dfs(v, u);
			siz.pb(dp[v]);
		}
	}
	sort(all(siz));
	reverse(all(siz));
	s = siz.size();
	if(s<k) return;
	f(i, 0, k-1)
	{
		dp[u]+=siz[i];
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, u, v;
	cin>>t;
	f(cas, 1, t)
	{
		g[1].pb(0);
		cin>>n>>k;
		f(i, 1, n-1)
		{
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1, 0);
		cout << "Case " << cas << ": " << dp[1] << "\n";
		f(i, 1, n) g[i].clear();
	}
	return 0;
}

