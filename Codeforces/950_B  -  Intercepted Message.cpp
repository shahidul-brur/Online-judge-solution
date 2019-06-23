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
int x[MAX], y[MAX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	f(i, 1, n) cin>>x[i];
	f(i, 1, m) cin>>y[i];
	ll s1 = 0LL, s2 = 0LL;
	int cnt = 0;
	for(int i=1, j = 1;i<=n && j<=m;)
	{
		s1+=x[i];
		s2+=y[j];
		if(s1==s2)
		{
			cnt++;
			++i;
			++j;
			continue;
		}
		if(s1<s2)
		{
			while(i+1<=n && s1+x[i+1]<=s2)
			{
				++i;
				s1+=x[i];
			}
			if(s1==s2)
			{
				cnt++;
			}
			++i;
			++j;
		}
		else if(s2<s1)
		{
			while(j+1<=m && s2+y[j+1]<=s1)
			{
				++j;
				s2+=y[j];
			}
			if(s1==s2)
			{
				cnt++;
			}
			++i;
			++j;
		}
	}
	cout << cnt << "\n";
	return 0;
}

