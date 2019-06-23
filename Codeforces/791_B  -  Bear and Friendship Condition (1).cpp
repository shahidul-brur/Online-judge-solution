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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9

vi g[150005];
int f[150005];
bool vis[150005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u, v;
    while(cin>>n>>m)
    {
        rep0(i, m)
        {
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            f[u]++;
            f[v]++;
        }
        int y = 1;
        rep1(i, n)
        {
            if(f[i]>1)
            {
                y = 0;
                break;
            }
        }
        if(y)
        {
            cout << "YES\n";
        }
        else
        {
            rep1(i, n)
            {
                g[i].pb(i);
                sort(all(g[i]));
            }
            y = 1;
            rep1(i, n)
            {
                int siz = g[i].size();
                if(siz>0)
                {
                    for(int j = 0;j<siz;j++)
                    {
                        int v = g[i][j];
                        if(!vis[v])
                        {
                            int ss = g[v].size();
                            if(siz!=ss)
                            {
                                y = 0;
                                break;
                            }
                            for(int k = 0;k<ss;k++)
                            {
                                if(g[v][k]!=g[i][k])
                                {
                                    y = 0;
                                    break;
                                }
                                
                            }
                            vis[v] = 1;
                            if(y==0)
                                break;
                        }
                    }
                }
                vis[i] = 1;
                if(y==0)
                    break;
            }
            if(y)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
