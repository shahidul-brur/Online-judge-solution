/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 200002;
const int MOD = 1000000007;
const int INF = (int)1e9;
vi g[MX+2], tree[MX];
int cnt[2], col[MX+2], h;
bool vis[MX];
bool vis2[MX];
bool vis3[MX];
void dfs(int u, int root)
{
    vis[u] = 1;
   // cout << "(for group " << root << ") " << u << ": " << col[u] << "\n============================\n";
    for(auto v : g[u])
    {
        if(vis[v]) continue;
        
        if(col[v]==col[u])
        {
            //cout << u << " to " << v << ", same color\n";
            dfs(v, root);
        }
        else
        {
            h++;
           // cout << u << " to " << v << ", diff color\n";
           // cout << "    so, h = " << h << "\n";
            tree[root].pb(h);
            tree[h].pb(root);
            dfs(v, h);
        }
    }
}
int mxh, mxNode, diameter;
void dfs2(int u, int lev)
{
    vis2[u] = 1;
    if(lev>mxh)
    {
        mxh = lev;
        mxNode = u;
    }
    for(auto v:tree[u])
    {
        if(!vis2[v])
            dfs2(v, lev+1);
    }
}
void dfs3(int u, int lev)
{
    vis3[u] = 1;
    if(lev>diameter)
    {
        diameter = lev;
    }
    for(auto v:tree[u])
    {
        if(!vis3[v])
            dfs3(v, lev+1);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    f(i, 1, n) cin>>col[i];
    f(i, 1, n-1)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    h = 0;
    f(i, 1, n)
    {
        if(!vis[i])
        {
            h++;
            dfs(i, h);
        }
    }
    /*
    for(int i = 1;i<=h;i++)
    {
        cout << i << ":\n.....\n";
        for(auto c : tree[i])
            cout << c << " , ";
        cout << "\n\n";
    }
    */
    dfs2(1, 0);
    dfs3(mxNode, 0);
    //cout << mxh << "#\n";
    cout << (diameter+1)/2 << "\n";
    return 0;
}


