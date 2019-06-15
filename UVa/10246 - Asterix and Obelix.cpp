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

int main()
{
    fast;
    in;
    //out;
    int road, city, q, u, v, w, visCost[85][85], hostCost[85], i, j, k, cas=1;
    while(cin>>city>>road>>q)
    {
        if(city==0)
            break;
        
        for(i=1;i<=city;i++)
            cin>>hostCost[i];
        
        for(i=1;i<=city;i++)
            for(j=1;j<=city;j++)
                if(i==j) visCost[i][j]=0;
                else visCost[i][j]=INF;
        for(i=1;i<=road;i++)
        {
            cin>>u>>v>>w;
            visCost[u][v]=visCost[v][u]=w;
        }
        
        for(k=1;k<=city;k++)
            for(i=1;i<=city;i++)
                for(j=1;j<=city;j++)
                    visCost[i][j] = min(visCost[i][j], visCost[i][k]+visCost[k][j]);
        
        
        if(cas>1) cout<< "\n";
        cout<< "Case #" <<cas<< "\n";
        for(i=1;i<=q;i++)
        {
            cin>>u>>v;
            if(visCost[u][v]==INF) cout<< "-1" << "\n";
            else cout<< visCost[u][v] + hostCost[v] << "\n";
        }
        cas++;
    }
    return 0;
}