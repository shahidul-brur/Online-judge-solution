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
int dx[]={1, -1, 0, 0, 0, 0};
int dy[]={0, 0, 1, -1, 0, 0};
int dz[]={0, 0, 0, 0, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef pair<int, pii> pti;

char grid[32][32][32];
int dist[32][32][32], R, C, L;
bool valid(int l, int r, int c)
{
    if(l<0 || l>=L || r<0 || r>=R || c<0 || c>=C)
        return 0;
    if(grid[l][r][c]=='#' || dist[l][r][c]!=-1)
        return 0;
    return 1;
}
void bfs(int sL, int sR, int sC)
{
    queue<pti> q;
    q.push(pti(sL, pii(sR, sC)));
    dist[sL][sR][sC]=0;
    while(!q.empty())
    {
        pti top = q.front(); q.pop();
        int l=top.first;
        int r=top.second.first;
        int c=top.second.second;
        for(int i=0;i<6;i++)
        {
            int nl = l + dx[i];
            int nr = r + dy[i];
            int nc = c + dz[i];
            
            if(valid(nl, nr, nc))
            {
                dist[nl][nr][nc] = dist[l][r][c] + 1;
                q.push(pti(nl, pii(nr, nc)));
            }
        }
    }
}
int main()
{
    fast;
    in;
    //out;
    int i, j, k, sR, sL, sC, eL, eR, eC;
    while(scanf("%d %d %d", &L, &R, &C)==3)
    {
        if(L==0) break;
        
        for(i=0;i<L;i++)
        {
            for(j=0;j<R;j++)
            {
                scanf("%s", grid[i][j]);
                for(k=0;k<C;k++)
                {
                    dist[i][j][k]=-1;
                    if(grid[i][j][k]=='S')
                        sR=j, sL=i, sC=k;
                    else if(grid[i][j][k]=='E')
                        eR=j, eL=i, eC=k;
                }
            }
        }
        
        bfs(sL, sR, sC);
        
        if(dist[eL][eR][eC]==-1)
            printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", dist[eL][eR][eC]);
    }
    return 0;
}