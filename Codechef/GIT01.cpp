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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
//             0123456789
const int MX = 100000;
char grid[105][105];
int n,m;
bool vis[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visit(int r, int c, char col){
    if(r<0 || r==n || c<0 || c==m || vis[r][c]==1) return 0;
    vis[r][c] = 1;
    int cnt = 0;
    if(grid[r][c] == 'R' && col == 'G')
        cnt = 5;
    else if(grid[r][c] == 'G' && col == 'R')
        cnt = 3;
    if(col=='G') col = 'R';
    else col = 'G';
    for(int i = 0;i<4;i++){
        cnt+=visit(r+dx[i], c+dy[i], col);
    }
    return cnt;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        f(i, 0, n-1) cin>>grid[i];
        mem(vis, 0);
        int ans = visit(0, 0, 'G');
        mem(vis, 0);
        ans = min(ans, visit(0, 0, 'R'));
        cout << ans << "\n";
    }
    return 0;
}

