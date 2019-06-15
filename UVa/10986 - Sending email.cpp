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
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
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
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

vpi AdjList[20002];
int dist[20002];
int dijkstra(int s)
{
    priority_queue<pii, vpi, greater<pii> > pq;
    dist[s]=0;
    pq.push(pii(0, s));
    while(!pq.empty())
    {
        pii top = pq.top(); pq.pop();
        int now = top.second;
        int cost = top.first;
        if(cost> dist[now]) continue;
        
        for(int i=0;i<(int)AdjList[now].size();i++)
        {
            int next = AdjList[now][i].second;
            int w = AdjList[now][i].first;
            
            if(dist[now] + w < dist[next])
            {
                dist[next] = dist[now] + w;
                pq.push(pii(dist[next], next));
            }
        }
    }
}
int main()
{
    fast;
    in;
    //out;
    int test, cas, u, v, w, m, n, S, T;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>n>>m>>S>>T;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            AdjList[u].pb(pii(w, v));
            AdjList[v].pb(pii(w, u));
        }
        for(int i=0;i<n;i++)
            dist[i]= INF;
        
        dijkstra(S);
        
        if(dist[T]==INF) printf("Case #%d: unreachable\n", cas);
        else printf("Case #%d: %d\n", cas, dist[T]);
        
        for(int i=0;i<n;i++) AdjList[i].clear();
    }
    return 0;
}