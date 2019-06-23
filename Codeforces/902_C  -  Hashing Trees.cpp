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
const int MX = 100005;
vector<int> level[MX];
vector<int> par[MX];
int tot[MX], h, id;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>h;
	int perf = 1;
	f(i, 0, h) 
	{
		cin>>tot[i];
		if(i>0 && tot[i-1]>1 && tot[i]>1) perf = 0;
	}
	if(perf)
	{
		cout << "perfect\n";
	}
	else
	{
		id = 0;
		int diff = -1;
		vector<int> d;
		level[0].pb(++id);
		par[0].pb(0);
		f(i, 1, h)
		{
			f(j, 0, tot[i]-1)
			{
				level[i].pb(++id);
			}
			for(int j = 0;j<tot[i];j++)
				par[i].pb(level[i-1][0]);
			if(diff==-1 && tot[i]>1 && tot[i-1]>1)
			{
				diff = i;
				for(int j = 0;j<tot[i]-1;j++)
					d.pb(level[i-1][0]);
				d.pb(level[i-1][1]);
			}
		}
		cout << "ambiguous\n";
		f(i, 0, h)
		{
			f(j, 0, tot[i]-1)
				cout << par[i][j] << " ";
		}
		cout << "\n";
		f(i, 0, h)
		{
			if(diff==i)
			{
				f(j, 0, tot[i]-1)
					cout << d[j] << " ";
			}
			else
			{
				f(j, 0, tot[i]-1)
					cout << par[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

