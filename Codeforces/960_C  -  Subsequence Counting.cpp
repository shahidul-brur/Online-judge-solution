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
int p2(ll x)
{
	f(i, 0, 30)
	{
		if(((1LL << (i+1)) - 1)>x)
			return i;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll x, d;
	cin>>x>>d;
	
	if(x<=10000)
	{
		cout << x << "\n";
		ll val = 1;
		f(i, 1, x)
		{
			if(i>1)
				cout << " ";
			cout << val;
			val+=d;
		}
		cout << "\n";
	}
	else
	{
		ll val = 1;
		vector<ll> ans;
		while(x>0)
		{
			int cnt = p2(x);
			f(i, 1, cnt)
				ans.pb(val);
			val+=d;
			x-=(1LL<<cnt)-1;
		}
		int s = ans.size();
		cout << s << "\n";
		f(i, 0, s-1)
		{
			if(i>0)
				cout << " ";
			cout << ans[i];
		}
		cout << "\n";
	}
	return 0;
}


