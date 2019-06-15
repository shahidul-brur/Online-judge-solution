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
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
int tim[30][30];
int dist[30][30];
void warshal(int node)
{
    for(int k=1;k<=node;k++)
        for(int i=1;i<=node;i++)
            for(int j=1;j<=node;j++)
                if(tim[i][k]+tim[k][j]<tim[i][j] || (tim[i][k]+tim[k][j]<=tim[i][j] && dist[i][k]+dist[k][j]<dist[i][j]))
                {
                    tim[i][j]=tim[i][k]+tim[k][j];
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
}
int main()
{
   fast;
   //in;
   //out;
   int test, cas, i, j, query, node, edge, d, t, u, v;
   cin>>test;
   for(cas=1;cas<=test;cas++)
   {
       cin>>node>>edge;
       for(i=1;i<=node;i++)
        for(j=1;j<=node;j++)
            if(i==j)
                tim[i][j]=dist[i][j]=0;
            else tim[i][j]=dist[i][j]=INF;
       for(i=1; i<=edge; i++)
       {
           cin>>u>>v>>t>>d;
           if(t<tim[u][v] || (t==tim[u][v] && d<dist[u][v]))
            {
                tim[u][v]=tim[v][u]=t;
                dist[u][v]=dist[v][u]=d;
            }
       }
       warshal(node);
       cin>>query;
       if(cas>1)
        cout<< "\n";
       for(i=1;i<=query;i++)
       {
           cin>>u>>v;
           
           if(dist[u][v]==INF)
                cout<<"No Path." << "\n";
           else 
                cout<<"Distance and time to reach destination is "<<dist[u][v]<<" & "<<tim[u][v]<<"." << "\n";
       }
   }
   return 0;
}