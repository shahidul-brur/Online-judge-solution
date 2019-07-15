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
int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[] = {-1, 1, 0, -1, 1, 0, -1, 1};
const int MX = 5002;
int n, m, a[MX][MX], maxi, d[MX][MX];
queue<ii> q;
int BFS()
{
    int cnt = 0;
    while(!q.empty())
    {
        int r = q.front().ff;
        int c = q.front().ss;
        q.pop();
        f(i, 0, 7)
        {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && a[nr][nc]!=maxi)
            {
                
//                cout << a[nr][nc] << " -> ";
                a[nr][nc] = maxi;
                cnt = d[nr][nc] = d[r][c] + 1;
//                cout << r << ", " << c << " : ";
//                cout << nr << ", " << nc << "\n";
                q.push(mp(nr, nc));
            }
        }
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
    while(t--)
    {
        cin>>n>>m;
        maxi = 0;
        f(i, 0, n-1)
        {
            f(j, 0, m-1)
            {
                cin>>a[i][j];
                maxi = max(maxi, a[i][j]);
            }
        }
        f(i, 0, n-1)
        {
            f(j, 0, m-1)
            {
                if(maxi == a[i][j])
                {
                    q.push(mp(i, j));
                    d[i][j] = 0;
                }
            }
        }
        int ans = BFS();
        cout << ans << "\n";
    }
    return 0;
}

