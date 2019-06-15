/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define rep(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
vi g[10002];
int city, mini, c[10002][10002], vis[10002];
void bfs()
{
    vis[1] = 1;
    queue<pair<int, pii> > q;
    q.push(make_pair(1, make_pair(0, 0)));
    while(!q.empty())
    {
        pair<int, pii > now = q.front(); q.pop();
        int u = now.first;
        int len = now.second.first;
        int cost = now.second.second;
        
        if(u==city && len%2==0)
        {
            mini = min(mini, cost);
        }
        else
        {
            for(int i=0;i<g[u].size();i++)
            {
                int v = g[u][i];
                if(vis[v]==0)
                {
                    vis[v] = 1;
                    q.push(make_pair(v, make_pair(len+1, cost+c[u][v])));
                    vis[v] = 0;
                }
            }
        }
    }
}
void dfs(int u, int len, int cost)
{
    if(u==city && len%2==0)
    {
        mini = min(mini, cost);
    }
    else
    {
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(vis[v]==0)
            {
                vis[v] = 1;
                dfs(v, len+1, cost+c[u][v]);
                vis[v] = 0;
            }
        }
    }
}
int main()
{
    fast;
    in;
    //out;
    int road, i, j, c1, c2, m;
    while(cin>>city>>road)
    {
        for(i=1;i<=road;i++)
        {
            cin>>c1>>c2>>m;
            g[c1].pb(c2);
            g[c2].pb(c1);
            c[c1][c2] = c[c2][c1] = m;
        }
        mini = 1000000007;
        mem(vis, 0);
        vis[1] = 0;
        dfs(1, 0, 0);
        if(mini == 1000000007)
            cout << "-1\n";
        else cout << mini << "\n";
        for(i=1;i<=city;i++)
            g[i].clear();
    }
    return 0;
}