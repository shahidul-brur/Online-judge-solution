/************************************************************
* Problem:   uva 11015
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
#define LL long long
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
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{
   //fast;
   //in;
   //out;
    int member, i, j, k, sum, minimum, path, a, b, c, cost[24][24], selected, cas=1;
    char name[25][13];
    while(cin>>member)
    {
        if(member==0)
            break;
        
        cin>>path;
        
        for(i=1;i<=member;i++)
            scanf("%s",name[i]);
        
        for(i=1;i<=member;i++)
            for(j=1;j<=member;j++)
                if(i==j)
                    cost[i][j]=0;
                else cost[i][j]=INF;
        
        for(i=1;i<=path;i++)
        {
            cin>>a>>b>>c;
            cost[a][b]=c;
            cost[b][a]=c;
        }
        
        for(k=1;k<=member;k++)
            for(i=1;i<=member;i++)
                for(j=1;j<=member;j++)
                    cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
        minimum=INF;
        for(i=1;i<=member;i++)
        {
            sum=0;
            for(j=1;j<=member;j++)
                if(cost[j][i]!=INF)
                    sum+=cost[j][i];
            if(sum<minimum)
            {
                minimum=sum;
                selected=i;
            }
            
        }
        cout<<"Case #"<<cas<<" : "<<name[selected]<<"\n";
        cas++;
    }
   return 0;
}