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
#define MLR int mid=(b+e)>>1,lft=v<<1,rgt=lft|1
#define INVALID -1
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)1e6+5;
const int LOGN = 20;
vii tree[4*maxn];
int arr[maxn];
void build(int v, int b, int e){
    if(b==e) return void(tree[v].pb(mp(arr[b],b)));
    MLR;build(lft,b,mid); build(rgt,mid+1,e);
    merge(all(tree[lft]),all(tree[rgt]),back_inserter(tree[v]));
}
int query(int v,int b,int e,int l,int r,int x){ // returned -1 means not found
    if(l>e || r<b) return INVALID;
    if(b>=l && e<=r){
        if(tree[v][0].first!=x) return tree[v][0].second;
        auto it = upper_bound(all(tree[v]),mp(x,INT_MAX));
        if(it==tree[v].end()) return INVALID;
        return (*it).second;
    }
    MLR;
    int ans = query(lft,b,mid,l,r,x);
    if(ans==INVALID) ans = query(rgt,mid+1,e,l,r,x);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    f1(i,n) cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        cout << query(1,1,n,l,r,x) << endl;
    }
    return 0;
}

