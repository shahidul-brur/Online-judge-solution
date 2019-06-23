/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
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
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

inline int Int(){int x; scanf("%d", &x);return x;}
inline long Long() {long x;scanf("%ld", &x);return x;}
inline ll LLong() {ll x;scanf("%lld", &x);return x;}
inline float Float() {float x;scanf("%f", &x);return x;}
inline float Double() {double x;scanf("%lf", &x);return x;}
inline ii Pair() {ii p; scanf("d %d", &p.ff, &p.ss);return p;}
void S(char *x) {scanf("%s", x);}

void pI(int x) {printf("%d", x);}
void pL(long x) {printf("%ld", x);}
void pLL(ll x) {printf("%lld", x);}
void pUL(ull x) {printf("%llu", x);}
void pF(float x) {printf("%f", x);}
void pD(double x) {printf("%f", x);}
void pS(char x[]) {printf("%s", x);}
#define pCas printf("Case %d:",cas)
#define NL printf("\n")
#define SP printf(" ")

#define I Int()
#define L Long()
#define LL LLong()
#define F Float()
#define D Double()
#define P Pair()

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = (int)1e9+7;
const int maxn = (int)1e5+5;
const int logn = 20;
vi g[maxn], cost[maxn];
int ans;
int a[maxn], par[maxn], siz[maxn];
int sub[maxn];
ll mx_path_cost[maxn];
stack<int> leafs;
void dfs(int u, int p)
{
    siz[u] = g[u].sz;
    sub[u] = 1;
    f0(i,g[u].sz)
    {
        int v = g[u][i];
        if(v==p) continue;
        par[v] = u;
        
        mx_path_cost[v] = max(mx_path_cost[u]+cost[u][i], 0LL);
        dfs(v, u);
        sub[u]+=sub[v];
    }
    //cout << u << " : " << mx_path_cost[u] << "..\n";
    if(mx_path_cost[u]>a[u])
    {
        ans+=sub[u];
        sub[u] = 0;
    }
    /*
        sads.insert()
    if(p!=0 && siz[u]==1)
        leafs.push(u);
        */
}
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = I;
    f1(i,n) a[i] = I;
    f1(i,n-1)
    {
        int u=I, v=i+1, w = I;
        g[u].pb(v);
        g[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    dfs(1,0);
    /*
    while(!leafs.empty())
    {
        int u = leafs.top(); leafs.pop();
        ans++;
        int p = par[u];
        siz[p]--;
        if(siz[p]==1 && mx_path_cost[p]>a[p])
        {
            leafs.push(p);
        }
    }
    */
    pI(ans);NL;
    return 0;
}
