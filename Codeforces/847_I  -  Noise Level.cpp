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
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//             0123456789
const int MX = 100000;
int val[255][255];
int n, m, q, p;
bool vis[255][255];
char g[255][255];
bool isValid(int r, int c)
{
    return (r>=0 && r<n && c>=0 && c<m && g[r][c]!='*');
}
void bfs(int r, int c, int v)
{
    mem(vis, 0);
    vis[r][c] =1;
    if(val[r][c]<=p)
        val[r][c]+=v;
    queue<pair<ii, int> > q;
    q.push(mp(mp(r, c), v/2));
    while(!q.empty())
    {
        pair<ii, int> cur = q.front(); q.pop();
        r = cur.ff.ff;
        c = cur.ff.ss;
        v = cur.ss;
        if(v==0)
            return;
        for(int i = 0;i<4;i++)
        {
            int nx = r+dx[i];
            int ny = c+dy[i];
            if(isValid(nx, ny) && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                if(val[nx][ny]<=p)
                    val[nx][ny]+=v;
                if(v/2>0)
                    q.push(mp(mp(nx, ny), v/2));
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>q>>p;
    mem(val, 0);
    for(int i = 0;i<n;i++)
        cin>>g[i];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(isupper(g[i][j]))
            {
                mem(vis, 0);
                //cout << "for " << g[i][j] << " ....\n\n";
                bfs(i, j, q*(g[i][j] - 'A'+1));
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            //cout << val[i][j] << "  ";
            if(val[i][j]>p)
                cnt++;
        }
        //cout << "\n";
    }
    cout << cnt << "\n";
    return 0;
}

