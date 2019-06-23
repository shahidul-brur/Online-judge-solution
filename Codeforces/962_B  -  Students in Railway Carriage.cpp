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

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int n, a, b;
	cin>>n>>a>>b;
	cin>>s;
	int cnt = 0, ans = 0;
	f(i, 0, n)
	{
		if(i==n || s[i]=='*') 
		{
			if(cnt==0)
				continue;
			int r = cnt%2;
			int need = cnt/2;
			int m = min(need,min(a, b));
			int add = m*2;
			ans+=m*2;
			a-=m;
			b-=m;
			if(a>=b && a>0)
				ans+=r, a-=r, add+=r;
			else if(b>0)
				ans+=r, b-=r, add+=r;
			cnt-=add;
			need = (cnt+1)/2;
			if(a>0)
				ans+=min(need, a), a-=min(need, a);
			else if(b>0)
				ans+=min(need, b), b-=min(need, b);
			cnt = 0;
		}
		else cnt++;
	}
	cout << ans << "\n";
	return 0;
}

