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
#define eps 1e-4
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000.0
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

vector<pdd> points;
double sqr(double a)
{
    return (a*a);
}
double dis(int a, int b)
{
    return (sqrt(sqr(points[a].first - points[b].first) + sqr(points[a].second - points[b].second)));
}
int main()
{
    //fast;
    in;
    //out;
    
    int test, cas, location, i, j, k;
    double dist[102][102], x, y;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>location;
        for(i=0;i<location;i++)
        {
            cin>>x>>y;
            points.push_back(pdd(x, y));
        }
        for(i=0;i<location;i++)
            for(j=0;j<location;j++)
                if(i==j) dist[i][j]=0.0;
                else dist[i][j]=INF;
        
        for(i=0;i<location;i++)
            for(j=0;j<location;j++)
                if(i!=j)
                    if(sqr(dis(i, j)) <= 100)
                        dist[i][j] = dis(i, j);
        
        for(k=0;k<location;k++)
            for(i=0;i<location;i++)
                for(j=0;j<location;j++)
                    if(dist[i][k] + dist[k][j] + eps < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                        
        double mx=0.0;
        int unreach=0;
        for(i=0;i<location && unreach==0;i++)
            for(j=0;j<location;j++)
                if(fabs(dist[i][j]-INF)<eps)
                {
                    unreach=1;
                    break;
                }
                else if(dist[i][j]>mx+eps)
                    mx=dist[i][j];
        
        printf("Case #%d:\n", cas);
        if(unreach==1) printf("Send Kurdy\n");
        else printf("%.4lf\n", mx);
        printf("\n");
        points.clear();
    }
    return 0;
}