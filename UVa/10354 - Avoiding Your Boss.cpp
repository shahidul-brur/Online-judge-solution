/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   
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
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int status[102], V, myHome;
bool valid;
int cost[102][102], path[102][102], path2[102][102], cost2[102][102];
void runWarshal()
{
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    {
                        cost[i][j] = cost[i][k] + cost[k][j];
                        path[i][j] = path[k][j];
                    }
}
void markPath(int from, int to)
{
    if(from!=to)
        markPath(from, path[from][to]);
    status[to]=1;
}
void runWarshal2()
{
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                if(status[k]==0 && cost2[i][k] + cost2[k][j] < cost2[i][j])
                    {
                        cost2[i][j] = cost2[i][k] + cost2[k][j];
                        path2[i][j] = path2[k][j];
                    }
}
void checkPath(int from, int to)
{
    if(from!=to)
        checkPath(from, path[from][to]);
    if(status[to]==1)
        valid=false;
}
int main()
{
   fast;
   in;
   //out;
   int bossHome, office, market, u, v, w, edge;
   while(cin>>V>>edge)
   {
       cin>>bossHome>>office>>myHome>>market;
       for(int i=1;i<=V;i++)
        {
            status[i]=0;
            for(int j=1;j<=V;j++)
            {
                path[i][j]=path2[i][j]=i;
                if(i==j)
                    cost[i][j]=cost2[i][j]=0;
                else cost[i][j]=cost2[i][j]=INF;
            }
        }
       for(int i=1;i<=edge;i++)
       {
           cin>>u>>v>>w;
           cost[u][v]=cost2[u][v]=w;
           cost[v][u]=cost2[v][u]=w;
       }
       valid=true;
       runWarshal();
       markPath(bossHome, office);
       /*
       for(int i=1;i<=V;i++)
            printf("%d - > %d\n", i, status[i]);
            */
       runWarshal2();
       checkPath(myHome, market);
       if(valid==false || cost2[myHome][market]==INF)
            printf("MISSION IMPOSSIBLE.\n");
       else printf("%d\n", cost2[myHome][market]);
   }
   return 0;
}