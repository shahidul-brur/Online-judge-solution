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
const int MX = 100002;
const int MOD = 1000000007;
const int INF = (int)1e9;
const int LOGN = 20;
set<int> g[MX];
int ans[MX], level[MX], lca[MX][LOGN];
int n, siz, sub[MX], par[MX];
void dfs_level(int u)
{
    for(auto it = g[u].begin();it!=g[u].end();it++)
    {
        int v = *it;
        if(lca[u][0]!=v)
        {
            level[v] = level[u]+1;
            lca[v][0] = u;
            dfs_level(v);
        }
    }
}
void preprocess()
{
    lca[0][0] = 0;
    level[0] = 0;
    dfs_level(0);
    ans[0] = 0;
    f(i, 1, LOGN-1)
        f(j, 0, n-1)
            lca[j][i] = lca[lca[j][i-1]][i-1], ans[j] = INF;
}
void dfs_subtree(int u, int p)
{
    sub[u] = 1;
    siz++;
    for(auto it = g[u].begin();it!=g[u].end();it++)
    {
        int v = *it;
        if(v!=p)
        {
            dfs_subtree(v, u);
            sub[u]+=sub[v];
        }
    }
}
int find_centroid(int u, int p)
{
    for(auto it = g[u].begin();it!=g[u].end();it++)
        if(*it != p && sub[*it]>siz/2)
            return find_centroid(*it, u);
    return u;
}
void decompose(int root, int p)
{
    siz = 0;
    dfs_subtree(root, root);
    int centroid = find_centroid(root, root);
    if(p==-1)
        p = centroid;
    par[centroid] = p;
    
    for(auto it = g[centroid].begin();it!=g[centroid].end();it++)
    {
        int v = *it;
        g[v].erase(centroid);
        decompose(v, centroid);
    }
    g[centroid].clear();
}
int LCA(int u, int v)
{
    if(level[u]>level[v])
        swap(u, v);
    int d = level[v] - level[u];
    
    f(i, 0, LOGN-1)
        if(d & (1<<i))
            v = lca[v][i];
    if(u==v)
        return u;
    
    F(i, LOGN-1, 0)
        if(lca[u][i]!=lca[v][i])
            u = lca[u][i], v = lca[v][i];
    
    return lca[u][0];
}
int dist(int u, int v)
{
    return level[u] + level[v] - 2*level[LCA(u, v)];
}
void update(int u)
{
    int p = u;
    while(1)
    {
        ans[p] = min(ans[p], dist(p, u));
        if(par[p]==p)
            return;
        p = par[p];
    }
}
int query(int u)
{
    int p = u;
    int mini = ans[u];
    while(1)
    {
        mini = min(mini, ans[p]+dist(p, u));
        if(par[p]==p)
            break;
        p = par[p];
    }
    return mini;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, u, v;
    cin>>n>>m;
    f(i, 1, n-1)
    {
        cin>>u>>v;
        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
    }
    preprocess();
    
    decompose(0, -1);
    //cout << LCA(4, 4) << "\n";
    update(0);
    while(m--)
    {
        int typ, node;
        cin>>typ>>node;
        
        if(typ==1)
            update(node-1);
        else
            cout << query(node-1) << "\n";
    }
    return 0;
}


