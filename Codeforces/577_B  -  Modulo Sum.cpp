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
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MX  = 1002;
const int INF = 2147483647;
int a[MX], n, m;
int ok[1003][1003];
int dp(int p, int r)
{
	if(r>0 && r%m==0)
		return 1;
	if(p>n)
		return 0;
	r%=m;
	if(ok[p][r]!=-1)
		return ok[p][r];
	return ok[p][r] = dp(p+1, r) || dp(p+1, r+a[p]);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m;
	f(i, 1, n)
	{
		cin>>a[i];
		if(i>=m || a[i]%m==0)
		{
			cout << "YES\n";
			return 0;
		}
	}
	mem(ok, -1);
	if(dp(1, 0))
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

