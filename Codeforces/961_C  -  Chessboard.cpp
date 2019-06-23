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
char grid[6][110][110];
int c[6][4];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	f(i, 1, 4)
	{
		f(j, 0, n-1)
			cin>>grid[i][j];
		f(j, 0, n-1)
		{
			f(k, 0, n-1)
			{
				char target;
				if( j % 2 == k%2 ) target = '1';
				else target = '0';
				if(grid[i][j][k]!=target)
					c[i][1]++;
				else c[i][2]++;
			}
		}
	}
	int ans = 10 * n * n;
	f(i, 1, 3)
	{
		f(j, i+1, 4)
		{
			int c1 = c[i][1] + c[j][1];
			f(k, 1, 4)
				if(k!=i && k!=j)
					c1 +=c[k][2];
			ans = min(ans, c1);
			int c2 = c[i][2] + c[j][2];
			f(k, 1, 4)
				if(k!=i && k!=j)
					c2 +=c[k][1];
			ans = min(ans, c2);
		}
	}
	cout << ans << "\n";
	return 0;
}


