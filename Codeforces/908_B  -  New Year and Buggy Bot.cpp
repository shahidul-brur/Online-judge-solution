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
int dd[] = {0, 1, 2, 3};
int dir[30][4];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char g[55][55];
int vis[55][55];

int n, m;
int sx, sy, ex, ey;
string ins;
bool reach;
void dfs(int r, int c, int pos, int t)
{
	if(r==ex && c==ey)
	{
		reach = 1;
		return;
	}
	if(pos>=ins.size()) return;
	int p = ins[pos] - '0';
	int nr = r + dx[dir[t][p]];
	int nc = c + dy[dir[t][p]];
	if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]!='#')
		dfs(nr, nc, pos+1, t);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	f(i, 0, 3) dir[1][i] = dd[i];
	int cur = 1;
	while(next_permutation(dd, dd+4))
	{
		++cur;
		f(i, 0, 3) dir[cur][i] = dd[i];
	}
	cin>>n>>m;
	
	f(i, 0, n-1)
	{
		cin>>g[i];
		f(j, 0, m-1)
		{
			if(g[i][j]=='S')
			{
				sx = i;
				sy = j;
			}
			else if(g[i][j]=='E')
			{
				ex = i;
				ey = j;
			}
		}
	}
	cin>>ins;
	int cnt=  0;
	f(i, 1, cur)
	{
		reach = 0;
		dfs(sx, sy, 0, i);
		if(reach)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}

