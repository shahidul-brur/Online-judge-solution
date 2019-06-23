
/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
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
vi adj[200005];
int total, mx, col[200005];
bool vis[200005];
map<int, int> maap;
void dfs(int u)
{
    vis[u] = 1;
    total++;
    maap[col[u]]++;
    mx = max(mx, maap[col[u]]);
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, a, b;
    while(cin>>n>>m>>k)
    {
        F(i, 1, n)
            cin>>col[i];
        F(i, 1, m)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int cnt = 0;
        F(i, 1, n)
        {
            if(!vis[i])
            {
                total = 0;
                mx = 0;
                dfs(i);
                cnt+=(total-mx);
                maap.clear();
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

