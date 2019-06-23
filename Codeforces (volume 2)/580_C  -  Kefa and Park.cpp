/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int cnt, cat[N+5], m;
vi adj[N+5];
bool vis[N+5];
void dfs(int u, int c)
{
    vis[u] = 1;
    //cout << u << " -> " << c << "\n";
    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            if(adj[v].size()==1)
            {
                if(c+cat[v]<=m)
                {
                   // cout << v << "\n";
                    cnt++;
                    vis[v]=1;
                }
            }
            else
            {
                if(cat[v] && c+1<=m)
                    dfs(v, c+1);
                else if(!cat[v]) dfs(v, 0);
            }
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n>>m)
    {
        F(i, 1, n)
            cin>>cat[i];
        F(i, 1, n-1)
        {
            int x, y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        dfs(1, cat[1]);
        cout << cnt << "\n";
    }
    return 0;
}
