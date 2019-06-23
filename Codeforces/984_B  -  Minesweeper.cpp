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
void sS(char *x) {scanf("%s", x);}

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

#define sI Int()
#define sL Long()
#define sLL LLong()
#define sF Float()
#define sD Double()
#define sP Pair()

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)3e5+5;
const int LOGN = 20;
char g[102][102];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1,-1, 1, -1, 0, 0, -1, 1};
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("int.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n=sI, m=sI;
    f0(i, n) sS(g[i]);
    int valid = 1;
    f0(i, n)
    {
        f0(j, m)
        {
            if(g[i][j]=='*') continue;
            int cnt = 0;
            if(g[i][j]=='.')
                cnt = 0;
            else if(g[i][j]>='0' && g[i][j]<='8')
                cnt = g[i][j] - '0';
            
            int tot = 0;
            f0(k, 8)
            {
                int r = i+dx[k];
                int c = j+dy[k];
                if(r>=0 && r<n && c>=0 && c<m && g[r][c]=='*')
                    tot++;
            }
            if(cnt!=tot)
            {
                    valid = 0;
                    //cout << i << " " << j << " " << tot << "\n";
                    break;
            }
        }
        if(!valid)
            break;
            
    }
    if(valid)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}

