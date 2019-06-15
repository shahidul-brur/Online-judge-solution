/************************************************************
* Problem:   
* Link:                                                     
* Verdict:  Accepted 
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
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef pair<int, pii>  pipi;

int cost[1002][1002], dist[1002][1002], M, N;
void dijkstra()
{
    priority_queue<pipi, vector<pipi>, greater<pipi> > pq;
    pq.push(pipi(cost[1][1], pii(1, 1)));
    dist[1][1] = cost[1][1];
    while(!pq.empty())
    {
        pipi top = pq.top(); pq.pop();
        int r = top.second.first;
        int c = top.second.second;
        int w = top.first;
        if(w > dist[r][c]) continue;
        
        for(int i=0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=1 && nr<=N && nc>=1 && nc<=M)
            {
                int w = cost[nr][nc];
                
                if(dist[r][c] + w < dist[nr][nc])
                {
                    dist[nr][nc] = dist[r][c] + w;
                    pq.push(pipi(dist[nr][nc], pii(nr, nc)));
                }
            }
        }
    }
}
int main()
{
    fast;
    //in;
    //out;
    int test, i, j;
    cin>>test;
    while(test--)
    {
        cin>>N>>M;
        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                cin>>cost[i][j];
        
        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                dist[i][j]=INF;
        dijkstra();
        cout<< dist[N][M] << "\n";
    }
   return 0;
}