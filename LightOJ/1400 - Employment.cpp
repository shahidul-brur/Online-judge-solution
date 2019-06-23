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
const int maxn = 505;
int rnkW[maxn][maxn], rnkM[maxn][maxn];
int marriedToM[maxn], prefW[maxn][maxn], prefM[maxn][maxn];
int marriedToW[maxn], nxt[maxn];
bool marriedM[maxn], marriedW[maxn];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=I;
    f1(cas,t)
    {
        fill(marriedM, marriedM+maxn, 0);
        fill(marriedW, marriedW+maxn, 0);
        fill(nxt, nxt+maxn, 1);
        int n=I;
        queue<int> q;
        f1(man,n)
        {
            q.push(man);
            f1(p,n)
            {
                int woman=I;
                prefM[man][p] = woman;
                rnkM[man][woman]=p;
            }
        }
        f1(woman,n)
        {
            f1(p,n)
            {
                int man=I;
                prefW[woman][p] = man;
                rnkW[woman][man]=p;
            }
        }
        while(!q.empty())
        {
            int man = q.front();
            int woman = prefM[man][nxt[man]];
            if(!marriedW[woman])
            {
                marriedM[man]=marriedW[woman]=1;
                marriedToM[man]=woman;
                marriedToW[woman]=man;
                q.pop();
            }
            else if(rnkW[man]<rnkW[marriedToW[woman]])
            {
                q.pop();
                q.push(marriedToW[woman]);
                marriedM[marriedToW[woman]]=0;
                marriedW[woman] = marriedM[man] = 1;
                marriedToW[woman] = man;
                marriedToM[man] = woman;
            }
            nxt[man]++;
        }
        printf("Case %d:",cas);
        f1(man,n)
        {
            printf(" (%d %d)",man, marriedToM[man]);
        }
        NL;
    }
    return 0;
}


