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
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MX  = 100002;
const int INF = 2147483647;

ll arr[MX];
int n, w, m;
bool check(ll x) // minimum = x is possible?
{
	vll cum(n+2, 0LL);
	int need = 0;
	f(i, 1, n)
	{
		cum[i]+=cum[i-1];
		int cur  = arr[i] + cum[i];
		if(cur<x)
		{
			need+=x-cur;
			if(need>m) return 0;
			cum[i]+=x-cur;
			if(i+w<=n)
				cum[i+w]-=x-cur;
		}
	}
	return 1;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m>>w;
	f(i, 1, n) cin>>arr[i];
	ll b = 1LL, e = 1e9 + 2e5; 
	ll ans = 0LL;
	while(b<=e)
	{
		ll mid = (b+e)/2;
		if(check(mid))
		{
			ans = max(ans, mid);
			b = mid+1;
		}
		else e = mid-1;
	}
	cout << ans << "\n";
	return 0;
}

