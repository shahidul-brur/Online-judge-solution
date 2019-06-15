/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   Accepted
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
vi graph[30002];
vi group[502];
int vis[502], member[502], cnt, visp[30002];
void dfs(int u)
{
    for(int i=0;i<graph[u].size();i++)
    {
        int grp = graph[u][i];
        if(!vis[grp])
        {
            vis[grp]=1;
            for(int j=0;j<member[grp];j++)
            {
                int v = group[grp][j];
                if(!visp[v])
                {
                    cnt++;
                    visp[v] = 1;
                    dfs(v);
                }
            }
        }
    }
}
int main()
{
    fast;
    in;
    //out;
    int n, m, i, j, id;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        
        for(i=0;i<m;i++)
        {
            cin>>member[i];
            for(j=0;j<member[i];j++)
            {
                cin>>id;
                group[i].pb(id);
                graph[id].pb(i);
            }
        }
        cnt = 0;
        mem(vis, 0);
        mem(visp, 0);
        dfs(0);
        if(cnt==0)
            cnt = 1;
        cout << cnt << "\n";
        for(i=0;i<n;i++)
            graph[i].clear();
        for(i=0;i<m;i++)
            group[i].clear();
    }
    return 0;
}