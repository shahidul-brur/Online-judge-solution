/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   ACCEPTED
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
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
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
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
int dr[]={0,  0, 1, -1, 1,  1, -1, -1};
int dc[]={1, -1, 0,  0, 1, -1,  1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
char grid[102][102];
int R, C;
bool vis[102][102];
int FloodFill(int row, int col)
{
    if(row<0 || row>=R || col<0 || col>=C)
        return 0;
    if(vis[row][col]==1 || grid[row][col]=='1')
        return 0;
    vis[row][col]=1;
    int ans=1;
    
    for(int i=0;i<4;i++)
    {
        ans+=FloodFill(row+dr[i], col+dc[i]);
    }
    return ans;
}
int main()
{
   //fast;
   in;
   //out;
    int test, cas, i, j, r, c;
    char temp[102];
    scanf("%d\n", &test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &r, &c);
        getchar();
        R=0;
        while(gets(temp))
        {
            if(temp[0]=='\0')
                break;
            strcpy(grid[R++], temp);
        }
        C=strlen(grid[0]);
        for(i=0;i<=R;i++)
            for(j=0;j<=C;j++)
                vis[i][j]=false;
        if(cas>1)
            printf("\n");
        printf("%d\n", FloodFill(r-1, c-1));
    }
   return 0;
}