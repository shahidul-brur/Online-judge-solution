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
const int maxn = (int)3e5;
const int LOGN = 20;
int par[2+maxn<<1], szx[2+maxn<<1], szy[2+maxn<<1];
int find(int u){
    return par[u]==u?u:find(par[u]);
}
ll ans;
struct upd{
    int u, v, sx, sy;
    upd(int _u, int _v, int _sx, int _sy){
        u=_u,v=_v,sx=_sx,sy=_sy;
    }
};
stack<upd> stk;
void rollback()
{
    upd cur = stk.top();stk.pop();
    ans-=1ll*szx[cur.u]*szy[cur.u];
    szx[cur.u]=cur.sx;
    szy[cur.u]=cur.sy;
    par[cur.v]=cur.v;
    ans+=1ll*szx[cur.u]*szy[cur.u];
    ans+=1ll*szx[cur.v]*szy[cur.v];
}
void make_union(int u, int v)
{
    u = find(u), v = find(v);
    if(u==v) return;
    if(szx[u]+szy[u]<szx[v]+szy[v]) swap(u,v);
    ans-=1ll*szx[v]*szy[v];
    ans-=1ll*szx[u]*szy[u];
    stk.push(upd(u,v,szx[u],szy[u]));
    szx[u]+=szx[v];
    szy[u]+=szy[v];
    ans+=1ll*szx[u]*szy[u];
    par[v]=u;
}
int l, r, val;
vi seg[2+maxn<<3];
void insert(int node, int b, int e)
{
    if(e<l || b>r) return;
    if(l<=b && e<=r){
        seg[node].pb(val);
        return;
    }
    int mid = (b+e)>>1, lft = node*2, rgt = lft+1;
    insert(lft,b,mid);
    insert(rgt,mid+1,e);
}
ll res[2+maxn];
ii E[2+maxn];
void dfs(int node, int b, int e)
{
    int stk_sz = stk.size();
    for(int i:seg[node]) make_union(E[i].ff, E[i].ss);
    if(b==e){
        res[b]=ans;
    }
    if(b!=e){
        int mid = (b+e)>>1, lft = node<<1, rgt = lft|1;
        dfs(lft,b,mid);
        dfs(rgt,mid+1,e);
    }
    while(stk.size()>stk_sz) rollback();
}
map<ii, int> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x, y;
    cin>>n;
    f1(i,n)
    {
        cin>>E[i].ff>>E[i].ss;
        E[i].ss+=maxn;
        if(m.find(E[i])==m.end()){
            m[E[i]] = i; 
        }
        else
        {
            l = m[E[i]];
            r = i-1;
            val = l;
            insert(1,1,n);
            m.erase(E[i]);
        }
    }
    f1(i,maxn) par[i]=i,szx[i]=1;
    f2(i,maxn+1,maxn<<1) par[i] = i, szy[i]=1;
    for(auto e:m){
        l = e.ss;
        r = n;
        val = l;
        insert(1,1,n);
    }
    dfs(1,1,n);
    f1(i,n) cout << res[i] << " ";
    return 0;
}