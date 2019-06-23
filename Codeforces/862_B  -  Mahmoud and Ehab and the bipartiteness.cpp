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
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
//             0123456789
const int MX = 100000;
vi g[MX+5];
int col[MX+5];
//int par[MX+5];
//int fin(int u)
//{
//    if(par[u]==u)
//        return u;
//    return par[u] = fin(par[u]);
//}
//void uni(int x, int y)
//{
//    int u = fin(x);
//    int v = fin(y);
//    if(u==v) return;
//    if(u<v)
//    {
//        par[v] = u;
//    }
//    else par[u] = v;
//}
bool vis[MX+5];
void dfs(int u, int c)
{
    vis[u] = 1;
    col[u] = c;
    int s = g[u].sz;
    f(i, 0, s-1)
    {
        int v = g[u][i];
        if(!vis[v])
            dfs(v, 1-c);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        f(i, 1, n-1)
        {
            int u, v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, 1);
        ll s1 = 0LL;
        f(i, 1, n)
            if(col[i]==1)
                s1++;
        
        ll tot = 1LL*s1*(n-s1);
        ll ans = tot - (n-1);
        cout << ans << "\n";
    }
    return 0;
}

