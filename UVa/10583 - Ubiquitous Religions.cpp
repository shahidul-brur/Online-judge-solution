/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               50005
#define inf             1e9

vi g[N];
bool vis[N];
void dfs(int u)
{
    vis[u] = 1;
    int s = g[u].sz;
    rep(i, s)
        if(!vis[g[u][i]])
            dfs(g[u][i]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int u, v, n, m, cnt, cas=1;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        rep1(i, n)
            vis[i] = 0, g[i].clear();
        rep(i, m)
        {
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cnt = 0;
        rep1(i, n)
            if(!vis[i])
                vis[i] = 1, cnt++, dfs(i);
        
        cout << "Case " << cas++ << ": " << cnt << "\n";
    }
    return 0;
}

