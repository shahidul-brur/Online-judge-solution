/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, n) for(ll i=0;i<n;i++)
#define FOR(i, b, a) for(int i=b;i>=a;i--)
#define sq(a) (a)*(a)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 200005
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
int n, m;
char g[105][105];
void dfs(int x, int y, char ch)
{
    g[x][y] = ch;
    char nxt;
    if(ch=='B')
        nxt = 'W';
    else nxt = 'B';
    
    rep(i, 4)
    {
        int r = x+dx4[i];
        int c = y+dy4[i];
        if(r>=0 && r<n && c>=0 && c<m && g[r][c]=='.')
            dfs(r, c, nxt);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        rep(i, n)
            cin>>g[i];
        rep(i, n)
            rep(j, m)
                if(g[i][j]=='.')
                    dfs(i, j, 'B');
        rep(i, n)
            cout << g[i] << "\n";
    }
    return 0;
}



