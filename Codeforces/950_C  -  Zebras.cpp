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
const int MAX = 200005;
string s;
vi ans[MAX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>s;
	int n = s.length();
	set<int> zero, one;
	f(i, 0, n-1)
	{
		if(s[i]=='1') one.insert(i+1);
		else zero.insert(i+1);
	}
	int k = 0;
	while(one.size()>0)
	{
		if(zero.size()==0)
		{
			cout << "-1\n";
			return 0;
		}
		int zp = *zero.begin();
		/*
		op = *one.begin();
		zp = *zero.begin();
		if(zp>op)
		{
			cout << "-1\n";
			return 0;
		}
		*/
		++k;
		ans[k].pb(zp);
		zero.erase(zp);
		while(1)
		{
			auto o = one.upper_bound(zp);
			if(o == one.end())
			{
				break;
			}
			else
			{
				int op = *o;
				auto z = zero.upper_bound(op);
				if(z==zero.end())
				{
					break;
				}
				else
				{
					zp = *z;
					ans[k].pb(op);
					ans[k].pb(zp);
					zero.erase(zp);
					one.erase(op);
				}
			}
		}
	}
	while(!zero.empty())
	{
		++k;
		ans[k].pb(*zero.begin());
		zero.erase(*zero.begin());
	}
	cout << k << "\n";
	f(i, 1, k)
	{
		int l = ans[i].size();
		cout << l;
		f(j, 0, l-1)
			cout << " " << ans[i][j];
		cout << "\n";
	}
	return 0;
}

