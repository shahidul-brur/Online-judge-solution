/************************************************************
* Problem:   
* Link:                                                     
* Verdict:  Accepted 
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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
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
#define all(v) v.begin(), v.end()
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

vi Depend[102], order;
bool vis[102];
void dfs(int u)
{
    vis[u]=1;
    
    for(int i=0; i<Depend[u].size();i++)
    {
        if(vis[Depend[u][i]]==0)
            dfs(Depend[u][i]);
    }
    order.pb(u);
}
int main()
{
    fast;
    in;
    //out;
    int n, m, task, dependOn, i;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        
        for(i=1; i<=m;i++)
        {
            cin>>dependOn>>task;
            Depend[task].push_back(dependOn);
        }
        
        for(i=1; i<=n;i++)
            vis[i]=0;
        
        for(i=1; i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        
        for(i=0; i<n;i++)
        {
            if(i>0)
                cout<< " ";
            cout<< order[i];
        }
        cout << "\n";
        
        for(i=1; i<=n;i++)
            Depend[i].clear();
        order.clear();
    }
    return 0;
}