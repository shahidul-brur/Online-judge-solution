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
char g[55][55];
int n, m;
bool vis[55][55];
bool visR[55];
vi rows;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	while(cin>>n>>m)
	{
		f(i, 0, n-1) cin>>g[i];
		bool yes = 1;
		mem(vis, 0);
		f(i, 0, n-1)
		{
			if(visR[i]) continue;
			rows.clear();
			bool cv =  0;
			f(j, 0, m-1)
			{
				if(g[i][j]== '#' && vis[i][j]){
					cv = 1;
					break;
				}
			}
			if(cv) continue;
			rows.pb(i);
			f(r, i+1, n-1)
			{
				bool ok = 1;
				f(j, 0, m-1)
				{
					if(g[i][j] != g[r][j]){
						ok = 0;
						break;
					}
					else if(g[r][j]=='#' && vis[r][j])
					{
						ok = 0;
						break;
					}
				}
				if(ok)
					rows.pb(r);
			}
			for(int rr:rows)
			{
				visR[rr] = 1;
				//cout << rr << " ";
				f(j, 0, m-1)
				{
					vis[rr][j] = 1;
					if(g[rr][j] == '#')
					{
						g[rr][j] = '.';
						f(k, 0, n-1)
							if(g[k][j] == '#')
								vis[k][j] = 1;
					}
				}
			}
			//cout << "\n";
		}
		f(i, 0, n-1)
		{
			f(j, 0, m-1)
			{
				if(g[i][j]=='#')
				{
					yes = 0;
					break;
				}
			}
		}
		if(yes)
			cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
