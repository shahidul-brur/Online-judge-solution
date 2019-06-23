#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define f(i, a, b, c) for(int i=(a);i!=(b);i+=(c))
inline int Int(){int x; scanf("%d", &x);return x;}
inline long Long() {long x;scanf("%ld", &x);return x;}
inline ll LLong() {ll x;scanf("%lld", &x);return x;}
inline float Float() {float x;scanf("%f", &x);return x;}
inline float Double() {double x;scanf("%lf", &x);return x;}
inline ii Pair() {ii p; scanf("%d%d", &p.ff, &p.ss);return p;}
void S(char *x) {scanf("%s", x);}
void pI(int x) {printf("%d", x);}
void pL(long x) {printf("%ld", x);}
void pLL(ll x) {printf("%lld", x);}
void pF(float x) {printf("%f", x);}
void pD(double x) {printf("%f", x);}
void pS(char x[]) {printf("%s", x);}
#define I Int()
#define L Long()
#define LL LLong()
#define F Float()
#define D Double()
#define P Pair()
#define NL printf("\n")
#define SP printf(" ")

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int MAX = 505;

int dis[MAX];
void dijkstra(vii g[], int src)
{
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(mp(0, src));
    dis[src] = 0;
    while(!pq.empty())
    {
        ii top = pq.top();pq.pop();
        int u = top.ss, d = top.ff;
        if(d>dis[u]) continue;
        f(i,0,g[u].size(),1)
        {
            ii nxt = g[u][i];
            int v = nxt.ss, w = nxt.ff;
            int mx = max(dis[u], w);
            if(mx>=dis[v]) continue;
            dis[v] = mx;
            pq.push(mp(mx, v));
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = I;
    f(cas,1,t+1,1)
    {
        int n = I, m = I;
        vii g[n+1];
        f(i,0,m,1)
        {
            int u = I;
            int v = I;
            int w = I;
            g[u].pb(mp(w,v));
            g[v].pb(mp(w,u));
        }
        f(i,0,n,1) dis[i] = INT_MAX;
        int src = I;
        dijkstra(g, src);
        printf("Case %d:\n", cas);
        f(i,0,n,1)
        {
            if(dis[i]==INT_MAX)
                printf("Impossible");
            else pI(dis[i]);
            NL;
        }
    }
    return 0;
}
