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
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;

bool vis[MX+5], L[MX+5];
vi g[MX+5];
int dis[MX+5];
double leaf, tot;
double prob[MX+5];
void dfs(int u, int p, int d)
{
    vis[u] = 1;
    dis[u] = d;
    if(u!=1)
    {
        int edg = g[p].size();
        if(p!=1)
            edg-=1;
        prob[u] = prob[p]*(1.0/(1.0*edg));
    }
    int s = g[u].size();
    if(s==1 && u!=1)
    {
        leaf+=1;
        tot+=dis[u]*prob[u];
    }
    f(i, 0, s-1)
    {
        int v = g[u][i];
        if(v==p) continue;
        dfs(v, u, d+1);
    }
}
int main()
{
   //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    
    if(n==1)
       {
           cout << "0.00000000\n";
           return 0;
       }
    f(i, 1, n-1)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        
    }
    leaf = 0.0;
    tot = 0.0;
    prob[1] = 1.0;
    dfs(1, -1, 0);
    cout << fixed << setprecision(10) << tot << "\n";
    return 0;
}


