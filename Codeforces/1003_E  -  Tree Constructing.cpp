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
inline double Double() {double x;scanf("%lf", &x);return x;}
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

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)4e5+5;
const int LOGN = 20;
int n;
vi lev[maxn];
vi adj[maxn];
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    n = Int();
    int d = Int(), k=Int();
    
    if(d==1)
    {
        if(n!=2)
            puts("NO");
        else
        {
            puts("YES");
            puts("1 2");
        }
        return 0;
    }
    if(n<d+1 || k==1)
    {
        puts("NO");
        return 0;
    }
    ll tot = k+1,  cur = k, l = 1;
    f2(i,2,d/2)
    {
        cur*=k-1;
        tot+=cur;
        if(i==1)
            l = 1;
        else l*=k-1;
        if(tot>=n) break;
    }
    if(tot<n && (d & 1))
        tot+=l*(k-1);
    //cout << tot << "#\n";
    if(n>tot)
    {
        puts("NO");
        return 0;
    }
    lev[0].pb(1);
    adj[1].pb(2), lev[1].pb(2);
    adj[1].pb(3), lev[1].pb(3);
    f1(i,d/2-1)
    {
        adj[2*i].pb(2*i+2);
        adj[2*i+1].pb(2*i+3);
        lev[i+1].pb(2*i+2);
        lev[i+1].pb(2*i+3);
        
    }
    if(d&1)
        adj[d-1].pb(d+1), lev[d/2+1].pb(d+1);
    f1(j,k)
        adj[d+1].pb(0), adj[d].pb(0);
    
    int node = d+2;
    while(node<=n && adj[1].size()<k)
        adj[1].pb(node), lev[1].pb(node++);

    f0(i,d)
    {
        if(node>n) break;
        for(int u:lev[i])
        {
            while(node<=n && adj[u].size()<k-1)
            {
                adj[u].pb(node);
                lev[i+1].pb(node++);
            }
            if(node>n) break;
        }
    }
    
    puts("YES");
    f1(u,n)
    {
        for(int v:adj[u])
        {
            if(v==0) continue;
            pI(u);SP;pI(v);NL;
        }
    }
    return 0;
}
