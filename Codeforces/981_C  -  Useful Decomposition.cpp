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

#define I Int()
#define L Long()
#define LL LLong()
#define F Float()
#define D Double()
#define P Pair()

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)1e5+5;
const int LOGN = 20;

vi g[maxn];
//bool ekadhik[maxn];

int n;
//
//void dfs(int u, int p)
//{
//    if(g[u].size())
//    for(int v:g[u])
//    {
//        if(v==p) continue;
//        dfs(v, u);
//    }
//}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>n;
    f1(i,n-1)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==2)
    {
        cout << "Yes\n1\n1 2\n";
        return 0;
    }
    
    int sz2 = 0, sz3 = 0, u=-1, v=-1, root=-1, common = -1;
    vi leafs;
    f1(i,n)
    {
        int s = g[i].sz;
        if(s>=3)
        {
            common = i;
            sz3++;
        }
        else if(s==2)
            sz2++;
        else if(s==1)
        {
            leafs.pb(i);
            if(u==-1) u = i;
            else v = i;
        }
        
        if(s == n-1)
            root = i;
    }
    
    //linear
    if(sz2==n-2)
    {
        cout << "Yes\n1\n";
        cout << u << " " << v << "\n";
        return 0;
    }
    // all to one
    if(root!=-1)
    {
        cout << "Yes\n";
        cout << n-1 << "\n";
        f1(i, n)
        {
            if(i!=root)
                cout << root << " " << i << "\n";
        }
        return 0;
    }
    
    
    if(sz3>1)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    int tot = leafs.size();
    cout << tot << "\n";
    f0(i, tot)
    {
        cout << common << " " << leafs[i] << "\n";
    }
    return 0;
}

