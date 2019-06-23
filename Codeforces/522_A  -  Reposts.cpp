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
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int id, mx;
map<string, int> mapp;
vi g[300];
bool vis[300];
void dfs(int u, int d)
{
    vis[u] = 1;
    mx = max(d, mx);
    for(auto v:g[u])
    {
        if(!vis[v])
        {
            dfs(v, d+1);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    string s1, s2;
    F(i, 1, n)
    {
        cin>>s1>>s2>>s2;
        transform(all(s1),s1.begin(), ::tolower);
        transform(all(s2),s2.begin(), ::tolower);
        if(mapp[s1]==0)
            mapp[s1]=++id;
        if(mapp[s2]==0)
            mapp[s2]=++id;
        g[mapp[s2]].pb(mapp[s1]);
    }
    //cout << g[mapp["Polycarp"]].size() << " ";
    dfs(mapp["polycarp"], 1);
    cout << mx << "\n";
    return 0;
}


