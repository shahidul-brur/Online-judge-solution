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
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const int logn = 18;
int nxt_val[maxn], nxt_pos[maxn][20];
int pos[maxn], perm[maxn], arr[maxn];
int finish[maxn];
int range_min[maxn<<2];
void build(int node, int b, int e)
{
    if(b==e){
        range_min[node] = finish[b];
        return;
    }
    build(node*2,b,(b+e)/2);
    build(1+node*2,(b+e)/2+1, e);
    range_min[node] = min(range_min[node*2],range_min[1+node*2]);
}
int query(int node, int b, int e, int l, int r)
{
    if(e<l || b>r) return maxn;
    if(b>=l && e<=r) return range_min[node];
    return min(query(node*2, b, (b+e)/2, l, r),
               query(node*2+1, (b+e)/2+1, e, l, r));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,q;
    cin>>n>>m>>q;
    f1(i,n) 
    {
        cin>>perm[i];
        if(i>1) nxt_val[perm[i-1]] = perm[i];
    }
    nxt_val[perm[n]] = perm[1];
    f1(i,m) cin>>arr[i];
    fr(i,m,1)
    {
        pos[arr[i]]= i;
        int nxt = nxt_val[arr[i]];
        nxt_pos[i][0] = pos[nxt];
    }
    f1(i,logn)
    {
        f1(idx, m)
        {
            int nxt = nxt_pos[idx][i-1];
            nxt_pos[idx][i] = nxt_pos[nxt][i-1];
        }
    }
    f1(i,m)
    {
        int idx = i, d = n-1;
        f0(k,logn) if(d&(1<<k))
            idx = nxt_pos[idx][k];
        if(idx==0) idx = maxn;
        finish[i] = idx;
    }
    build(1,1,m);
    while(q--)
    {
        int l, r; 
        cin>>l>>r;
        int rgt = query(1,1,m,l,r);
        if(rgt>=l && rgt<=r) cout << "1";
        else cout << "0";
    }
    return 0;
}
