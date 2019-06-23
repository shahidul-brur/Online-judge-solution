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
const int MAX = 100005;
char g[505][505];
int R, C;
bool canAttack, vis[505][505];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int r, int c)
{
	vis[r][c] = 1;
	if(g[r][c]== 'S')
	{
		canAttack = 1;
		return;
	}
	f(i, 0, 3)
	{
		int nr = r + dx[i];
		int nc = c + dy[i];
		if(nr>=0 && nr<R && nc>=0 && nc<C && (g[nr][nc]=='.' || g[nr][nc]=='S'))
			dfs(nr, nc);
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>R>>C;
	f(i, 0, R-1)
	{
		cin>>g[i];
	}
	f(i, 0, R-1)
	{
		f(j, 0, C-1)
		{
			if(g[i][j]=='W')
			{
				if(i>0 && g[i-1][j]=='.')
					g[i-1][j] = 'D';
				if(i<R-1 && g[i+1][j]=='.')
					g[i+1][j] = 'D';
				if(j>0 && g[i][j-1]=='.')
					g[i][j-1] = 'D';
				if(j<C-1 && g[i][j+1]=='.')
					g[i][j+1] = 'D';
			}
		}
	}
	canAttack = 0;
	f(i, 0, R-1)
	{
		f(j, 0, C-1)
		{
			if(!vis[i][j]  && g[i][j]=='W')
			{
				dfs(i, j);
				if(canAttack==1)
					break;
			}
		}
		if(canAttack==1)
			break;
	}
	if(canAttack==1)
		cout << "No\n";
	else 
	{
		cout << "Yes\n";
		f(i, 0, R-1)
			cout << g[i] << "\n";
	}
	return 0;
}

