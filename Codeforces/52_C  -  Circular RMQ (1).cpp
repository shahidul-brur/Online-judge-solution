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
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
inline ii Pair() {ii p; scanf("%d %d", &p.ff, &p.ss);return p;}
void Char(char *x) {scanf("%s", x);}

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
ll arr[maxn], tree[4*maxn], lazy[4*maxn];
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int lft = node<<1, rgt = lft|1, mid = (b+e)>>1;
    build(lft,b,mid);
    build(rgt,mid+1,e);
    tree[node] = min(tree[lft], tree[rgt]);
}
void push_down(int node, int b, int e)
{
    if(lazy[node]==0) return;
    tree[node]+=lazy[node];
    if(b!=e)
    {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int b, int e, int l, int r, int val)
{
    push_down(node, b, e);
    if(b>r || e<l || b>e) return;
    if(b>=l && e<=r)
    {
        lazy[node]+=val;
        push_down(node,b,e);
        return;
    }
    int lft = node<<1, rgt = lft|1, mid = (b+e)>>1;
    update(lft,b,mid,l,r,val);
    update(rgt,mid+1,e,l,r,val);
    tree[node] = min(tree[lft], tree[rgt]);
}
ll query(int node, int b, int e, int l, int r)
{
    push_down(node, b, e);
    if(b>e || b>r || e<l) return LLONG_MAX;
    if(b>=l && e<=r) return tree[node];
    int lft = node<<1, rgt = lft|1, mid = (b+e)>>1;
    ll ql = query(lft, b, mid, l, r);
    ll qr = query(rgt, mid+1, e, l, r);
    return min(ql, qr);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n; cin>>n;
    f1(i,n) cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    cin.ignore();
    while(q--)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        vi v;
        int x;
        while(ss>>x)
            v.pb(x);
        v[0]++;
        v[1]++;
        //cout << " # \n";
        if(v.size()==2) // query
        {
            if(v[0]<=v[1])
                cout << query(1,1,n,v[0],v[1]) << "\n";
            else
            {
                ll q1 = query(1,1,n,v[0],n);
                ll q2 = query(1,1,n,1,v[1]);
                cout << min(q1,q2) << "\n";
            }
        }
        else
        {
            if(v[0]<=v[1])
                update(1,1,n,v[0],v[1],v[2]);
            else
            {
                update(1,1,n,v[0],n,v[2]);
                update(1,1,n,1,v[1],v[2]);
            }
        }
    }
    return 0;
}