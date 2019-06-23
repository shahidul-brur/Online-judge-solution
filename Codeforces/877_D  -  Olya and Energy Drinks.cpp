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
const int MAX = 1005;
char g[MAX][MAX];
bool vis[MAX][MAX][5];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dis[MAX][MAX];
int n, m, sx, sy, fx, fy, k;
int bfs()
{
    mem(vis, 0);
    rep0(i, n) rep0(j, m) dis[i][j]=1000000009;
    dis[sx][sy] = 0;
     
    vis[sx][sy][1] = 1;
    vis[sx][sy][0] = 1;
    queue<ii> q;
    q.push(mp(sx, sy));
    while(!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;
        int dir = 0;
        //right, 0
        for(int i = cx, j=cy+1, cnt = 1;cnt<=k && j<m;j++, cnt++)
        {
            if(vis[i][j][dir] || g[i][j]=='#') break;
            vis[i][j][dir] = 1;
            dis[i][j] = min(dis[i][j], dis[cx][cy] + 1);
            if(i==fx && j==fy) return dis[i][j];
            q.push(mp(i, j));
        }
        //left, 0
        for(int i = cx, j=cy-1, cnt = 1;cnt<=k && j>=0;j--, cnt++)
        {
            if(vis[i][j][dir] || g[i][j]=='#') break;
            vis[i][j][dir] = 1;
            dis[i][j] = min(dis[i][j], dis[cx][cy] + 1);
            if(i==fx && j==fy) return dis[i][j];
            q.push(mp(i, j));
        }
        
        dir++;
        //up, 1
        for(int i = cx-1, j=cy, cnt = 1;cnt<=k && i>=0;i--, cnt++)
        {
            if(vis[i][j][dir] || g[i][j]=='#') break;
            vis[i][j][dir] = 1;
            dis[i][j] = min(dis[i][j], dis[cx][cy] + 1);
            if(i==fx && j==fy) return dis[i][j];
            q.push(mp(i, j));
        }
         
        //down, 1
        for(int i = cx+1, j=cy, cnt = 1;cnt<=k && i<n;i++, cnt++)
        {
            if(vis[i][j][dir] || g[i][j]=='#') break;
            vis[i][j][dir] = 1;
            dis[i][j] = min(dis[i][j], dis[cx][cy] + 1);
            if(i==fx && j==fy) return dis[i][j];
            q.push(mp(i, j));
        }
    }
    return -1;
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
        scanf("%d %d %d", &n, &m, &k);
        rep0(i, n)
        {
            scanf("%s", g[i]);
        }
        scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
        --sx;
        --sy;
        --fx;
        --fy;
        int d;
        if(sx==fx && sy==fy)
            d = 0;
        else 
            d = bfs();
        printf("%d\n", d);
    
    return 0;
}
