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
const int mod = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
vi g[maxn];
vi c[maxn];
int n, k;
int pwr(int b, int e)
{
    if(e==0) return 1;
    if(e==1) return b;
    int ret = pwr(b,e/2);
    ret = (ret*1LL*ret)%mod;
    if(e&1) ret=(ret*1LL*b)%mod;
    return ret;
}
int tot;
bool vis[maxn];
void dfs(int u)
{
    vis[u]=1;
    tot++;
    int s = g[u].size();
    f0(i,s)
    {
        if(vis[g[u][i]]==0 && c[u][i]==0)
            dfs(g[u][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>k;
    f1(i,n-1)
    {
        int u, v, col;
        cin>>u>>v>>col;
        g[u].pb(v);
        g[v].pb(u);
        c[u].pb(col);
        c[v].pb(col);
    }
    ll ans = pwr(n,k);
    ll bad = 0LL;
    f1(i,n)
    {
        if(!vis[i]){
            tot=0;
            dfs(i);
            bad = (bad + pwr(tot,k))%mod;
        }
    }
    ans-=bad;
    if(ans<0) ans+=mod;
    cout << ans;
    return 0;
}
