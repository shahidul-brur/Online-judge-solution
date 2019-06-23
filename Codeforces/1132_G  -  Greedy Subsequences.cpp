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
const int maxn = (int)1e6+5;
const int LOGN = 20;
int tree[4*maxn], lazy[4*maxn];
void propagate(int node, int b, int e){
    if(lazy[node]==0)
        return;
    tree[node]+=lazy[node];
    if(b!=e){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node] = 0;
}

int query(int node, int b, int e, int l, int r){
    propagate(node, b, e);
    if(l>e || r<b)
        return 0LL;
    if(b>=l && e<=r) 
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    return max(query(Left, b, mid, l, r), query(Right, mid + 1, e, l, r));
}
void update(int node, int b, int e, int l,int r, int add){
    propagate(node, b, e);
    if(l>e || r<b)
        return;
    if(b>=l && e<=r){
        lazy[node]=add;
        propagate(node, b, e);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, l, r, add);
    update(Right, mid + 1, e, l, r, add);
    tree[node] = max(tree[Left], tree[Right]);
}
int a[maxn], ans[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin>>n>>k;
    vi v;
    v.pb(0);
    a[0] = INT_MAX;
    f1(i,n){
        cin>>a[i];
        while(!v.empty() && a[i]>a[v.back()]) v.pop_back();
        update(1,1,n,v.back()+1,i,+1);
        v.pb(i);
        if(i>=k) ans[i] = query(1,1,n,i-k+1,i);
    }
    f2(i,k,n) cout << ans[i] << " ";
    return 0;
}
