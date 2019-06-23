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

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	scanf("%d", &t);
	f(cas, 1, t)
	{
		int n, q;
		scanf("%d %d", &n, &q);
		vector<int> points(n);
		vector<ii> seg(q);
		vector<int> val;
		f(i, 0, n-1) scanf("%d", &points[i]), val.pb(points[i]);
		f(i, 0, q-1) scanf("%d %d", &seg[i].ff, &seg[i].ss), val.pb(seg[i].ff), val.pb(seg[i].ss);
		sort(all(val));
		val.erase(unique(all(val)), val.end());
		map<int, int> maap;
		int siz = val.size();
		vector<int> sum(siz+1, 0);
		f(i, 0, siz-1) maap[val[i]] = i;
		f(i, 0, n-1) points[i] = maap[points[i]]+1, sum[points[i]]++;
		f(i, 1, siz) sum[i]+=sum[i-1];
		
		printf("Case %d:\n", cas);
		f(i, 0, q-1) printf("%d\n", sum[maap[seg[i].ss]+1] - sum[maap[seg[i].ff]]);;
	}
	return 0;
}

