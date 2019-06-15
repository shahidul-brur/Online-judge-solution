/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   WA
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
#define FORN(i, n) for(i = 0; i < n; i++)
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
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int guard[202];
vi AdjList[202];
int bfs(int from)
{
    queue<int> q;
    q.push(from);
    guard[from] = 1;
    int need = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0;i<AdjList[u].size();i++)
        {
            int v = AdjList[u][i];
            if(guard[v]==-1)
            {
                guard[v] = 1 - guard[u];
                need +=guard[v];
                q.push(v);
            }
            else if(guard[v]==guard[u])
                return -1;
        }
    }
    return need;
}
int main()
{
    fast;
    in;
    //out;
    int test, node, edge, i, j, u, v, ans, need;
    cin>>test;
    while(test--)
    {
        cin>>node>>edge;
        for(i=0;i<=node;i++)
            guard[i] = -1;
        for(i=0;i<edge;i++)
        {
            cin>>u>>v;
            AdjList[u].pb(v);
            AdjList[v].pb(u);
        }
        
        ans=0;
        for(i=0;i<node;i++)
        {
            if(AdjList[i].size()>0 && guard[i]==-1)
            {
                need = bfs(i);
                if(need==-1)
                    break;
                else ans+=need;
            }
        }
        if(need==-1)
            cout << "-1" << "\n";
        else cout<< ans << "\n";
        for(i=0;i<=node;i++)
            AdjList[i].clear();
    }
    return 0;
}