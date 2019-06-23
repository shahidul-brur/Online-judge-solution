#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define F0(i,b) for(int i=(b);i>=0;i--)
#define F1(i,b) for(int i=(b);i>=1;i--)
#define F(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b) for(int i=(a);i!=(b);i+=(c))

inline int Int(){int x; scanf("%d", &x);return x;}
inline long Long() {long x;scanf("%ld", &x);return x;}
inline ll LLong() {ll x;scanf("%lld", &x);return x;}
inline float Float() {float x;scanf("%f", &x);return x;}
inline float Double() {double x;scanf("%lf", &x);return x;}
inline ii Pair() {ii p; scanf("d", &p.ff, &p.ss);return p;}
void S(char *x) {scanf("%s", x);}
void pI(int x) {printf("%d", x);}
void pL(long x) {printf("%ld", x);}
void pLL(ll x) {printf("%lld", x);}
void pUL(ull x) {printf("%llu", x);}
void pF(float x) {printf("%f", x);}
void pD(double x) {printf("%f", x);}
void pS(char x[]) {printf("%s", x);}
#define I Int()
#define L Long()
#define LL LLong()
//#define F Float()
#define D Double()
#define P Pair()
#define NL printf("\n")
#define SP printf(" ")
#define pCas printf("Case %d:",cas)

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)3e5+5;
const int LOGN = 20;
int parent[maxn][LOGN];
int level[maxn], sub[maxn];
vector<int> g[maxn];

void dfs(int u){
    sub[u] = 1;
	for(auto v:g[u]){
        if(v!=parent[u][0]){
			parent[v][0]=u;
			level[v]=level[u]+1;
			dfs(v);
			sub[u]+=sub[v];
		}
    }
}
/*
void preprocess(int n){
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];
			//parent[5][1] = parent[parent[5][1-1]][1-1];
}
*/
/*
int lca(int a,int b)
{
	if(level[a]>level[b])
        swap(a,b);
	int d = level[b] - level[a];
	for(int i = 0; i < LOGN;i++)
		if(d &(1<<i))
			b = parent[b][i];
	if(a==b)
        return a;
	for(int i=LOGN-1;i>=0;i--)
		if(parent[a][i]!=parent[b][i])
			a=parent[a][i],b=parent[b][i];
	return parent[a][0];
}
*/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, x, y, u, v;
    cin>>n>>x>>y;
    f(i,1,n-1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    //preprocess(n);
    bool samepath  = 0;
    u = x, v = y;
    if(level[v]>level[u])
        swap(u,v);
    ll up=0LL, dwn=0LL;
    while(1)
    {
        int p = parent[u][0];
        if(p==v)
        {
            samepath = 1;
            up = n - sub[u];
            break;
        }
        if(u==1) break;
        u = p;
    }
    u = x, v = y;
    if(level[v]>level[u])
        swap(u,v);
    ll ans = 0;
    if(!samepath)
    {
        up = sub[v];
    }
    dwn = sub[u];
    ans = (ll)n*1LL*(n-1) - up*1LL*dwn;
    cout << ans << "\n";
    return 0;
}

