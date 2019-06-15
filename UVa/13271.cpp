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
const int MX = 100000;
ll same_row(ll ca, ll cb)
{
	return abs(ca-cb);
}
ll same_col(ll ra, ll rb, ll c)
{
	ll dir = abs(ra-rb)/2;
	ll ind = abs(ra-rb) - dir;
	if(ra%2==c%2)
		swap(dir, ind);
	return dir + 3*ind;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll ra, ca, rb, cb;
	while(cin>>ra>>ca>>rb>>cb)
	{
		if(ra==0)
			break;
			
		ll ans = 0LL;
		if(rb<ra)
		{
			swap(ra, rb);
			swap(ca, cb);
		}
		if(ra==rb)
			ans = same_row(ca, cb);
		else if(ca==cb)
		{
			ans = same_col(ra, rb, ca);
		}
		else
		{
			ll rdif = abs(ra-rb);
			ll cdif = abs(ca-cb);
			
			if(cdif >= rdif)
				ans = rdif + cdif;
			else 
			{
				ans = cdif *2;
				ra+=cdif;
				ans += same_col(ra, rb, cb);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

