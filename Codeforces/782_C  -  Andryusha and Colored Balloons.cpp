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
#define N             200005
bool vis[N];
int col[N];
vi g[N];
void dfs(int u, int rt)
{
    vis[u] = 1;
    //cout << u << " -> " << rt << "\n";
    int s = g[u].size();
    int id = 1;
    rep0(i, s)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            if(rt==id || col[u]==id)
                id++;
            if(rt==id || col[u]==id)
                id++;
            col[v] = id++;
            dfs(v, col[u]);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, u, v, k;
    while(cin>>n)
    {
        mem(vis, 0);
        k = 1;
        rep1(i, n-1)
        {
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            k = max(k, (int)g[u].size());
            k = max(k, (int)g[v].size());
        }
        col[1] = 1;
        dfs(1, 0);
        cout << k+1 << "\n";
        rep1(i, n)
            cout << col[i] << " ";
        cout << "\n";
        rep1(i, n)
            g[i].clear();
    }
    return 0;
}

