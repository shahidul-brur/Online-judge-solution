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
int a[MX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, mini, mid;
	while(cin>>n)
	{
		cin>>a[1];
		mini = a[1];
		f(i, 2, n) 
		{
			cin>>a[i];
			mini = min(mini, a[i]);
		}
		int las = -1, md = 200000000;
		f(i, 1, n) 
		{
			if(a[i]==mini)
			{
				if(las==-1)
					las = i;
				else 
				{
					md = min(md, i-las);
					las = i;
				}
			}
		}
		cout << md << "\n";
	}
	return 0;
}

