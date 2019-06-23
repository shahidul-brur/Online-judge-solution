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
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 1005;
int n, m, sx, sy;
char g[MAX][MAX];
bool pos;
int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};
bool vis[MAX][MAX][4][4];
void dfs(int x, int y, int dir, int mov)
{
    //cout << x << " " << y << "\n";
    if(x<0 || y<0 || x>=n || y>=m) return;
    if(g[x][y]=='S' || g[x][y]=='*' || vis[x][y][dir][mov]==1)
        return;
    if(g[x][y]=='T') {pos=1; return;}
    vis[x][y][dir][mov]=1;
    f(i, 0, 3)
    {
        if(pos==1)
            break;
        int nx = x+xx[i];
        int ny = y+yy[i];
        
        if(i==dir)
            dfs(nx, ny, i, mov);
        else if(mov<2)
            dfs(nx, ny, i, mov+1);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n>>m)
    {
        f(i, 0, n-1) cin>>g[i];
        f(i, 0, n-1) f(j, 0, m-1) if(g[i][j]=='S') {sx= i; sy=j;break;}
        pos=0;
        f(i, 0, 3)
        {
            int nx = sx+xx[i];
            int ny = sy+yy[i];
            dfs(nx, ny, i, 0);
        }
        if(pos)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

