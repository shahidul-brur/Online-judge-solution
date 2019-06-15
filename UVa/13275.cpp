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
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, d, m, y, qy;
	cin>>t;
	f(cas, 1, t)
	{
		cin>>d>>m>>y>>qy;
		cout << "Case " << cas << ": ";
		int cnt = 0;
		if(d==29 && m==2)
		{
			f(i, y+1, qy)
			{
				if(i%400==0 || (i%4==0 && i%100!=0))
					cnt++;
			}
		}
		else
		{
			cnt = qy-y;
		}
		cout << cnt << "\n";
	}
	return 0;
}

