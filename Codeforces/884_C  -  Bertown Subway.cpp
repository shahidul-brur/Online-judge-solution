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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
const int MX = 100002;
vi g[MX];
bool vis[MX];
int p[MX];
vi comp;
int n;
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    cnt++;
    int s = g[u].sz;
    f(i, 0, s-1)
        if(!vis[g[u][i]])
            dfs(g[u][i]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    f(i, 1, n)
    {
        cin>>p[i];
        g[i].pb(p[i]);
    }
    f(i, 1, n)
    {
        cnt = 0;
        if(!vis[i])
            dfs(i);
        if(cnt>0)
            comp.pb(cnt);
    }
    ll ans = 0LL;
    sort(all(comp));
    int s = comp.sz;
    if(s==1)
        ans = 1LL*comp[0]*comp[0];
    else
    {
        ans = 1LL*(comp[s-1]+comp[s-2]);
        ans*=ans;
        f(i, 0, s-3)
        {
            ans+=1LL*comp[i]*comp[i];
        }
    }
    cout << ans << "\n";
    return 0;
}

