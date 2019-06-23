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
const int MAX = 100005;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, r, a, ans = 0;
	cin>>l>>r>>a;
	if(l==r)
	{
		ans = 2*l;
		if(a%2==0)
			ans+=a;
		else ans+=(a-1);
	}
	else if(l>r)
	{
		int need = l-r;
		if(a>=need)
		{
			ans = 2*l;
			a-=need;
			if(a%2==0)
				ans+=a;
			else ans+=(a-1);
		}
		else
		{
			r+=a;
			ans = 2*min(l, r);
		}
	}
	else
	{
		int need = r-l;
		if(a>=need)
		{
			ans = 2*r;
			a-=need;
			if(a%2==0)
				ans+=a;
			else ans+=(a-1);
		}
		else
		{
			l+=a;
			ans = 2*min(l, r);
		}
	}
	cout << ans << "\n";
	return 0;
}

