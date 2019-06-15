/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   Accepted
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

char grid[53][53];
int vis[53][53];
int floodFill(int r, int c)
{
    vis[r][c]=1;
    int gold = 0;
    if(grid[r][c]=='G')
        gold++;
    
    int goNext = 1;
    for(int i=0;i<4;i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(grid[nr][nc]=='T')
        {
            goNext=0;
            break;
        }
    }
    
    if(goNext==1)
    {
        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(grid[nr][nc]!='#' && !vis[nr][nc])
            {
                gold+=floodFill(nr, nc);
            }
        }
    }
    return gold;
}
int main()
{
    //fast;
    in;
    //out;
    int R, C;
    int pR, pC, ans;
    while(cin>>C>>R)
    {
        pR=pC=-1;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<R;i++)
        {
            cin>>grid[i];
            if(pR==-1)
            {
                for(int j=0;j<C;j++)
                    if(grid[i][j]=='P')
                    {
                        pR=i;
                        pC=j;
                    }
            }
        }
        
        ans = floodFill(pR, pC);
        cout << ans << "\n";
    }
    return 0;
}