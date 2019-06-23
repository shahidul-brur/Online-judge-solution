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
#define F Float()
#define D Double()
#define P Pair()
#define NL printf("\n")
#define SP printf(" ")
#define pCas printf("Case %d:",cas)

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
ll a[maxn];
ll s[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m; cin>>n>>m;
    f(i, 1, n) 
    {
        cin>>a[i];
        s[i]= s[i-1]+a[i];
    }
    f(i, 1, m) 
    {
        ll r;
        cin>>r;
        ll dor, room, b = 1, e = n;
        while(b<=e)
        {
            int mid = (b+e)>>1;
            if(s[mid]<r)
            {
                b = mid+1;
            }
            else if(s[mid]>=r)
            {
                e = mid-1;
                dor = mid;
            }
        }
        room = r - s[dor-1];
        cout << dor << " " << room << "\n";
    }
    return 0;
}

