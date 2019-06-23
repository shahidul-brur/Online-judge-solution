#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long

// ---------------- typedef ------------------------------
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

// --------------   template ends  ------------------------
vi g[200005];
int d[200005];
void bfs()
{
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        int i;
        //cout << "  # " << u << ":\n";
        for(i=0; i<g[u].size();i++)
        {
            int v = g[u][i];
            if(v!=1 && d[v]==0)
            {
                //cout << "      -> " << v << ".\n";
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        //cout << "....\n";
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, n, v;
    cin>>n;
    F(i, 1,n)
    {
        cin>>v;
        if(v!=i)
            g[i].pb(v);
        
        if(i>1)
            g[i].pb(i-1);
        if(i<n)
            g[i].pb(i+1);
    }
    bfs();
    
    F(i, 1, n)
    {
        cout << d[i] << " ";
    }
    return 0;
}


