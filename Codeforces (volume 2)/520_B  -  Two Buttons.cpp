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
int n, m;
int vis[3000005];
int bfs(int u)
{
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        int v = cur*2;
        if(v>0 && v<=10*m && !vis[v])
        {
            vis[v] = vis[cur] +1 ;
            if(v==m)
                return vis[m];
            q.push(v);
        }
        v = cur-1;
        if(v>0 && !vis[v])
        {
            vis[v] = vis[cur] + 1 ;
            if(v==m)
                return vis[m];
            q.push(v);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, i, j;
    cin>>n>>m;
    if(n==m)
        cout << "0\n";
    cout << bfs(n)-1 << "\n";
    return 0;
}

