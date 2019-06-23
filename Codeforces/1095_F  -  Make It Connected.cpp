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

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
vector<pair<ll, int> > node;
ll a[maxn];
vector<pair<ll, ii> > edge;
int p[maxn];
int findP(int u)
{
    if(u==p[u]) return u;
    return (p[u] = findP(p[u]));
}
void make_union(int u, int v){
    int pu = findP(u);
    int pv = findP(v);
    if(pu==pv) return;
    if(a[pu]<a[pv]){
        p[pv] = pu;
        a[pv] = a[pu];
    }
    else
    {
        p[pu] = pv;
        a[pu] = a[pv];
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    f1(i,n){
        cin>>a[i];
    }
    f0(i,m){
        int u,v; 
        ll w;
        cin>>u>>v>>w;
        edge.pb(mp(w, mp(u,v)));
    }
    int root = 1;
    ll root_w = a[1];
    f1(i,n){
        if(a[i]<root_w){
            root = i;
            root_w = a[i];
        }
    }
    
    f1(i,n){
        if(i!=root){
            edge.pb(mp(root_w+a[i], mp(root, i)));
        }
    }
    sort(all(edge));
    ll ans = 0LL;
    int e = edge.size();
    f1(i,n) p[i]=i;
    f0(i,e)
    {
        int u1 = edge[i].ss.ff;
        int u2 = edge[i].ss.ss;
        ll ew = edge[i].ff;
        int p1 = findP(u1);
        int p2 = findP(u2);
        if(p1!=p2){
            ans+=ew;
            make_union(p1,p2);
        }
    }
    cout << ans;
    return 0;
}
