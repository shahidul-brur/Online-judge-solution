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
#define f(i, a, b, c) for(int i=(a);i!=(b);i+=(c))

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

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int MAXN = 5000002;
bool is_composite[MAXN];
ull phi[MAXN];
vi prime;
void sieve (int n) {
	fill(is_composite, is_composite + n, false);
	for (ll i = 2; i <= n; ++i) {
		if (!is_composite[i]) {
			prime.push_back(i);
			phi[i] = i - 1;					//i is prime
		}
		for (int j = 0; i*prime[j]<=n && j < prime.size(); ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
	f(i, 2, n+1,1)
        phi[i]=phi[i-1]+phi[i]*phi[i];
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve(5000000);
    int t = I;
    f(cas,1,t+1,1)
    {
        int a=I,b=I;
        ll ans=phi[b]-phi[a-1];
        printf("Case %d: ",cas);
        pUL(ans);NL;
    }
    return 0;
}

