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
double ans[1005];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<pair<int, double> > pts;
	int r;
	int n, x;
	cin>>n>>r;
	cin>>x;
	ans[1] = r;
	pts.pb(mp(x, 1.0*r));
	f(i, 2, n)
	{
		double my = r;
		cin>>x;
		int siz = pts.size();
		f(j, 0, siz-1)
		{
			int px = pts[j].ff;
			double py = pts[j].ss;
			if(px>x-2*r || px<x+2*r)
			{
				double curY = sqrt((1.0*4*r*r) - 1.0*(x-px)*(x-px)) + py;
				my = max(my, curY);
			}
		}
		ans[i] = my;
		pts.pb(mp(x, my));
	}
	f(i, 1, n)
		cout << fixed << setprecision(10) <<  ans[i] << " ";
	return 0;
}

