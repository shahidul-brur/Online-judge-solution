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

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
const int MX = 1e5+5;
int tree[4*MX][2];
int lazy[4*MX];
int a[maxn], l[maxn], r[maxn];
int n, m;
vi add_seg[maxn], del_seg[maxn];
void propagate(int node, int b, int e){
    if(lazy[node]==0)
        return;
    tree[node][0]+=lazy[node];
    tree[node][1]+=lazy[node];
    if(b!=e){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node] = 0;
}
void build(int node, int b, int e){
    if (b == e){
        tree[node][0] = a[b];
        tree[node][1] = a[b];
        lazy[node] = 0LL;
        return;
    }
    
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node][0] = min(tree[Left][0], tree[Right][0]);
    tree[node][1] = max(tree[Left][1], tree[Right][1]);
    lazy[node] = 0LL;
}
int query(int t, int node, int b, int e, int l, int r){
    propagate(node, b, e);
    if(l>e || r<b)
        return 0LL;
    if(b>=l && e<=r) 
        return tree[node][t];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int ql = query(t, Left, b, mid, l, r);
    int qr = query(t, Right, mid + 1, e, l, r);
    int ret;
    if(t==0) ret = min(ql,qr);
    else ret = max(ql, qr); 
    return ret;
}
void update(int node, int b, int e, int l,int r, ll add){
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
    tree[node][0] = min(tree[Left][0], tree[Right][0]);
    tree[node][1] = max(tree[Left][1], tree[Right][1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    f1(i,n) cin>>a[i];
    f1(i,m){
        cin>>l[i]>>r[i];
        add_seg[l[i]].pb(i);
        del_seg[r[i]].pb(i);
    }
    int ans, id, mx = a[1], mini = a[1];
    int q = 0;
    f1(i,n){
        mx = max(mx, a[i]);
        mini = min(mini, a[i]);
    }
    ans = mx - mini;
    if(m==0){
        cout << ans << "\n" << "0\n";
        return 0;
    }
    build(1,1,n);
    f1(i,n){
        int k = add_seg[i].size();
        f0(j,k){
            int seg = add_seg[i][j];
            update(1,1,n,l[seg],r[seg],-1);
        }
        mx = query(1,1,1,n,1,n);
        mini = query(0,1,1,n,1,n);
        int cur= mx - mini;
        if(cur>ans){
            ans = cur;
            id = i;
            q = 1;
        }
        k = del_seg[i].size();
        f0(j,k){
            int seg = del_seg[i][j];
            update(1,1,n,l[seg],r[seg],+1);
        }
    }
    cout << ans << "\n";
    if(q==0){
        cout << "0\n";
        return 0;
    }
    q = 0;
    f1(i,m) if(l[i]<=id && r[i]>=id) 
        q++;
    cout << q << "\n";
    f1(i,m) if(l[i]<=id && r[i]>=id) 
        cout << i << " ";
    return 0;
}