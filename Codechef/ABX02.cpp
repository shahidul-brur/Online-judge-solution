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
const int MX  = 100002;
const int INF = 2147483647;
ll s[3], b[3], tot[3], N;
ll dp[2][200][200];
ll bx[3];
ll fn(int box, int S, int stp)
{
	if(stp>N)
		return 0;
	if(dp[box][S][stp]!=-1)
		return dp[box][S][stp];
	ll cur = 1LL;
	if(S<s[box] && bx[box]<b[box])
	{
		bx[box]++;
		cur+=fn(box, S+1, stp+1)%MOD;
		bx[box]--;
	}
	if(bx[3-box]<b[3-box])
	{
		bx[3-box]++;
		cur+=fn(3-box, 1, stp+1)%MOD;
		bx[3-box]--;
	}
	dp[box][S][stp] = cur;
	return dp[box][S][stp];
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>tot[2]>>tot[2]>>N;
		cin>>b[1]>>b[2];
		cin>>s[1]>>s[2];
		mem(dp, -1);
		ll ans = fn(1, 0, 1);
		cout << ans << "\n";
	}
	return 0;
}

