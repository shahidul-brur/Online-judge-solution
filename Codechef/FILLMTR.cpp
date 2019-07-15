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
const int MX = 100005;
int ara[MX];
vi same[MX], diff[MX];
bool yes, vis[MX];
void dfs(int u, int d)
{
    vis[u] = 1;
    ara[u] = d;
    
    int s = same[u].sz;
    f(i, 0, s-1)
    {
        int v = same[u][i];
        if(ara[v]!=-1 && ara[v]!=d)
        {
            yes = 0;
            return;
        }
        if(!vis[v])
            dfs(v, d);
    }
    
    s = diff[u].sz;
    f(i, 0, s-1)
    {
        int v = diff[u][i];
        if(ara[v]!=-1 && ara[v]==d)
        {
            yes = 0;
            return;
        }
        if(!vis[v])
            dfs(v, 1-d);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, r, c, d, q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        f(i, 1, n) 
        {
            ara[i] = -1; 
            vis[i] = 0; 
            same[i].clear(); 
            diff[i].clear();
        }
        f(i, 0, q-1)
        {
            cin>>r>>c>>d;
            if(d==1)
                diff[r].pb(c), diff[c].pb(r);
            else same[r].pb(c), same[c].pb(r);
        }
        yes = 1;
        f(i, 1, n)
        {
            if(!vis[i])
                dfs(i, 0);
            if(!yes) break;
        }
        if(yes)
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

