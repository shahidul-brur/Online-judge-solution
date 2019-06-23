/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 200005;
int dis1[MX];
int dis2[MX];
vi g[MX];
bool vis1[MX];
bool vis2[MX];
void bfs()
{
	dis1[1]=0;
	vis1[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		int siz = g[u].size();
		f(i, 0, siz-1)
		{
			int v = g[u][i];
			if(!vis1[v])
			{
				vis1[v] = 1;
				dis1[v] = dis1[u] + 1;
				q.push(v);
			}
		}
	}
}
int bfs2(int x)
{
	dis2[x]=0;
	vis2[x]=1;
	int ans = dis1[x];
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		int siz = g[u].size();
		f(i, 0, siz-1)
		{
			int v = g[u][i];
			if(!vis2[v])
			{
				vis2[v] = 1;
				dis2[v] = dis2[u] + 1;
				ans = max(ans, max(dis1[v], dis2[v]));

				if(dis1[v]>dis2[v])
					q.push(v);
			}
		}
	}
	return ans*2;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, u, v;
    cin>>n>>x;
    f(i, 1, n-1)
    {
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    bfs();
    int ans = bfs2(x);
    cout << ans << "\n";
    return 0;
}
