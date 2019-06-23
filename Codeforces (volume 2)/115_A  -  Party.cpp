/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
vi adj[2005], root;
bool vis[2005];
int mx;
void dfs(int u, int d)
{
    vis[u] = 1;
   // cout << u << "#\n";
    mx = max(d, mx);
    for(auto v: adj[u])
    {
        if(!vis[v])
            dfs(v, d+1);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, n;
    while(cin>>n)
    {
        F(i, 1, n)
        {
            cin>>a;
            if(a!=-1)
                adj[a].pb(i);
            else root.pb(i);
        }
        int cnt=0;
        int r=root.size();
        F(i, 0, r-1)
        {
            //cout << 
            dfs(root[i], 1);
        }
       // mx = max(mx, cnt);
        cout << mx << "\n";
    }
    return 0;
}
