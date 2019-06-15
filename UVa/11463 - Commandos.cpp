/************************************************************
*  Problem: UVa 11463                                                
* Link:     http://uva.onlinejudge.org/external/114/11463.html                                                
* Verdict:  Accepted                                                
* Date:     2015/09/20                                                
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
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define LL long long
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
#define INF 1e9
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{
   fast
   in
   //out
   int building, road, b1, b2, i, j, k, time, test, cas, cost[102][102], from, to;
   cin>>test;
   for(cas=1;cas<=test;cas++)
   {
       cin>>building>>road;
       for(i=0;i<=building;i++)
            for(j=0;j<=building;j++)
                if(i==j)
                    cost[i][j]=0;
                else
                    cost[i][j]=INF;
        for(i=1;i<=road;i++)
        {
            cin>>b1>>b2;
            cost[b1][b2]=1;
            cost[b2][b1]=1;
        }
        cin>>from>>to;
        for(k=0;k<building;k++)
            for(i=0;i<building;i++)
                for(j=0;j<building;j++)
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        time=0;
        
        for(i=0;i<building;i++)
            if(cost[from][i] + cost[i][to]>time)
                time=cost[from][i] + cost[i][to];
        printf("Case %d: %d\n", cas, time);
   }
   return 0;
}