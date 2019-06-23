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

inline int getInt(){int x; scanf("%d", &x);return x;}
inline long getLong() {long x;scanf("%ld", &x);return x;}
inline ll getLLong() {ll x;scanf("%lld", &x);return x;}
inline float getFloat() {float x;scanf("%f", &x);return x;}
inline double getDouble() {double x;scanf("%lf", &x);return x;}
inline ii getPair() {ii p; scanf("%d %d", &p.ff, &p.ss);return p;}
void getCAra(char *x) {scanf("%s", x);}
string getString() {char ch[200005]; scanf("%s", &ch); string s = string(ch); return s;}

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
const int maxn = (int)2e5+5;
const int LOGN = 20;
int a[maxn], nxt[maxn], pre[maxn], len[maxn];
struct cmp
{
    bool operator()(ii a, ii b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n; 
    while(cin>>n){//;
    vii v;
    f1(i,n)
    {
        cin>>a[i];
        v.pb(mp(a[i],i));
    }
    sort(all(v));
    int id = 1;
    a[v[0].ss] = 1;
    f1(i,n-1)
    {
        if(v[i].ff>v[i-1].ff) ++id;
        a[v[i].ss] = id;
    }
    pre[1] = 0;
    set<ii, cmp> siz;
    f1(i,n)
    {
        int p = i;
        while(i+1<=n && a[i+1]==a[i]) ++i;
        nxt[p] = i+1;
        pre[i+1] = p;
        len[p] = i-p+1;
        siz.insert(mp(len[p], p));
    }
    int ans = 0;
    while(!siz.empty()){
        int seg = (*siz.begin()).ff;
        int pos = (*siz.begin()).ss;
        siz.erase(siz.begin());
        if(seg>=1)
            ++ans;
        if(pre[pos]>0 && nxt[pos]<=n && a[pre[pos]]==a[nxt[pos]])
        {
            int s1 = len[nxt[pos]], s2 = len[pre[pos]];
            siz.erase(mp(s1, nxt[pos]));
            siz.erase(mp(s2, pre[pos]));
            
            nxt[pre[pos]] = nxt[nxt[pos]];
            pre[nxt[nxt[pos]]] = pre[pos];
            
            len[pre[pos]] = s1 + s2;
            siz.insert(mp(s1+s2, pre[pos]));
        }
        else 
        {
            nxt[pre[pos]] = nxt[pos];
            pre[nxt[pos]] = pre[pos];
        }
    }
    cout << ans << endl;
    }
    return 0;
}
