#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
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
int a[30005], n;
bool vis[30005];
void dfs(int u)
{
    if(u>n)
        return;
    vis[u] = 1;

    if(!vis[u+a[u]])
        dfs(u+a[u]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, i, j;
    cin>>n>>t;
    F(i, 1, n-1)
        cin>>a[i];
    dfs(1);
    if(vis[t])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
