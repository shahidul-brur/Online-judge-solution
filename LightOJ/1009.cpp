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

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 200003;
bool vis[MAX];
int siz[2];
vi g[MAX];
int id[MAX], m, p[MAX];
void dfs(int u, int typ)
{
    vis[u]=1;
    siz[typ]++;
    //cout << p[u] << ", " << typ << " :\n";
    int s = g[u].sz;
    for(int i = 0;i<s;i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            //cout << p[v] << " #\n";
            dfs(v, 1-typ);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, u, v, t, cas;
    cin>>t;
    rep1(cas, t)
    {
        cin>>n;
        m = 0;
        mem(vis, 0);
        mem(id, 0);
        rep0(i, n)
        {
            cin>>u>>v;
            if(id[u]==0)
            {
                ++m;
                //p[m] = u;
                id[u] = m;
            }
            if(id[v]==0)
            {
                ++m;
                //p[m] = v;
                id[v] = m;
            }
            v = id[v];
            u = id[u];
            g[u].pb(v);
            g[v].pb(u);
        }
        int ans =0;
        rep1(i, m)
        {
            if(!vis[i])
            {
                siz[0] = siz[1] = 0;
                dfs(i, 1);
                ans+=max(siz[1], siz[0]);
            }
        }
        cout << "Case " << cas << ": " << ans << "\n";
        rep1(i, m)
        {
            g[i].clear();
        }
    }
    return 0;
}

