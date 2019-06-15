//Accepted

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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;
int g[105][105], n, domi[105][105];
bool vis[105], con[105];

void dfs1(int u)
{
    con[u]=1;
    for(int i=0;i<n;i++)
    {
        if(g[u][i]==1 && con[i]==0)
        {
            dfs1(i);
        }
    }
}

void dfs2(int u, int del)
{
   // cout <<  u << ": \n";
    vis[u] = 1;
    if(u==del)
        return;
   for(int i=0;i<n;i++)
    {
        if(i!=del && g[u][i]==1 && vis[i]==0)
        {
            dfs2(i, del);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, cas, i, j;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            con[i]=0;
            for(j=0;j<n;j++)
            {
                domi[i][j]=0;
                cin>>g[i][j];
            }
        }
        dfs1(0);
        //for(int i=0;i<n;i++)
           // cout << con[i] << ", ";
        //cout << "\n";
        for(int i=0;i<n;i++)
        {
            if(con[i]==1)
            {
                
                domi[i][i]=1;
                memset(vis, 0, sizeof(vis));
                dfs2(0, i);
                //cout << "ok " << i <<"\n";
                for(int j=0;j<n;j++)
                    if(con[j]==1 && vis[j]==0)
                        domi[i][j]=1;
            }
        }
        cout << "Case " << cas << ":\n+";
        for(int i=1;i<=2*n-1;i++)
            cout << "-";
        cout << "+\n";
        for(i=0;i<n;i++)
        {
            cout << "|";
            for(j=0;j<n;j++)
            {
                if(domi[i][j]==1)
                    cout << "Y|";
                else cout << "N|";
            }
            cout << "\n+";
            for(int j=1;j<=2*n-1;j++)
                cout << "-";
            cout << "+\n";
        }
    }
    return 0;
}

