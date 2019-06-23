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
const int maxn = (int)1e5+5;
const int N = (int)1e6, bit = 21;

bool B[bit+3][maxn], lazy[bit+3][4*maxn];
int tree[bit+3][4*maxn];
void propagate(int t, int node, int b, int e)
{
    if(!lazy[t][node]) return;
    //cout << "Came to propagate " << node << "[" <<  b << ", " << e << "] : " << tree[t][node] << " -> ";
    tree[t][node] = e - b + 1 - tree[t][node];
    //cout << tree[t][node] << "\n";
    if(b!=e){
        lazy[t][2*node]^=1;
        lazy[t][2*node+1]^=1;
    }
    lazy[t][node] = 0;
}
void build(int t, int node, int b, int e)
{
    //cout << "Came to build " << node << "[" <<  b << ", " << e << "]";
    if (b == e){
        tree[t][node] = B[t][b];
        //cout << " : " << tree[t][node] << "\n";
        return;
    }
    //else cout << "\n";
   
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    //cout << "Going to build " << Left << "[" <<  b << ", " << mid << "]\n";
    build(t, Left, b, mid);
    //cout << "Going to build " << Right << "[" <<  mid+1 << ", " << e << "]\n";
    build(t, Right, mid + 1, e);
    tree[t][node] = tree[t][Left] + tree[t][Right];
    //cout << "Back to " << node << ": " <<  tree[t][Left] << " + " << tree[t][Right] << " =  " << tree[t][node] << "\n";
}
 
int query(int t, int node, int b, int e, int l, int r)
{
    propagate(t,node, b, e);
    if(e<l || r<b) return 0;
    //cout << "Came to query " << node << "[" <<  b << ", " << e << "]";
    if(b>=l && e<=r){
        //cout << ": " << tree[t][node] << "\n";
        return tree[t][node];
    }
    //else cout << "\n";
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    //cout << "Going to query " << Left << "[" <<  b << ", " << mid << "]\n";
    int ql = query(t,Left, b, mid, l,r);
    //cout << "Going to query " << Right << "[" <<  mid+1 << ", " << e << "]\n";
    int qr = query(t,Right, mid+1, e, l,r);
    //cout << "Back to " << node << ": " <<  ql << " + " << qr << " =  " << ql+qr << "\n";
    return ql+qr;
}
 
void update(int t,int node, int b, int e, int l, int r)
{
    //cout << "Came to update " << node << "[" <<  b << ", " << e << "]";
    propagate(t,node, b, e);
    if(l>e || r<b)
        return;
    if(b>=l && e<=r){
        lazy[t][node] ^= 1;
        propagate(t,node, b, e);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(t,Left, b, mid, l, r);
    update(t,Right, mid + 1, e, l, r);
    tree[t][node] = tree[t][Left]+tree[t][Right];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,a;
    cin>>n;
    f1(i,n) 
    {
        cin>>a;
        f0(j,bit) if(a & (1<<j))
            B[j][i] = 1;
    }
    f0(i,bit) 
    {
        //cout << "building tree : " << i << "\n===========\n";
        build(i,1,1,n);
        //cout << "\n\n";
    }
    int m;
    cin>>m;
    while(m--)
    {
        int typ, l, r, x;
        cin>>typ;
        if(typ==1)
        {
            cin>>l>>r;
            ll p2 = 1;
            ll ans = 0, one = 0;
            f0(j,bit)
            {
                //cout << "Querying tree " << i << "\n=========\n";
                ll q =  query(j,1,1,n,l,r);
                //cout << "      =====> " << q << "\n\n";
                one+=q;
                ans+=(one%2)*p2;
                p2<<=1LL;
                one/=2;
            }
            while(one)
            {
                ans+=(one%2)*p2;
                p2<<=1LL;
                one/=2;
            }
            cout << ans << endl;
        }
        else
        {
            cin>>l>>r>>x;
            f0(j,bit)if(x & (1LL<<j))
            {
                update(j,1,1,n,l,r);
            }
        }
    }
    return 0;
}

