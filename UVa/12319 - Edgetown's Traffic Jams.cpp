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
   int node, i, j, k, A, B, u, v, old[102][102], newer[102][102];
   char temp[1000], *token;
   while(scanf("%d\n", &node)==1)
   {
       if(node==0) break;
       
       for(i=1;i<=node;i++)
            for(j=1;j<=node;j++)
                if(i==j) old[i][j]=newer[i][j]=0;
                else old[i][j]=newer[i][j]=INF;
       for(i=1;i<=node;i++)
       {
           gets(temp);
           token=strtok(temp, " ");
           sscanf(token, "%d", &u);
           token=strtok(NULL, " ");
           while(token!=NULL)
           {
               sscanf(token, "%d", &v);
               old[u][v]=1;
               token=strtok(NULL, " ");
           }
       }
       
       for(i=1;i<=node;i++)
       {
           gets(temp);
           token=strtok(temp, " ");
           sscanf(token, "%d", &u);
           token=strtok(NULL, " ");
           while(token!=NULL)
           {
               sscanf(token, "%d", &v);
               newer[u][v]=1;
               token=strtok(NULL, " ");
           }
       }
       scanf("%d %d", &A, &B);
        
        for(k = 1; k <= node; k++)
            for(i=1;i<=node;i++)
                for(j=1;j<=node;j++)
                {
                    old[i][j]=min(old[i][j], old[i][k]+old[k][j]);
                    newer[i][j]=min(newer[i][j], newer[i][k]+newer[k][j]);
                }
                
        int yes=1;
        for(i=1;i<=node && yes==1;i++)
            for(j=1;j<=node;j++)
                if(newer[i][j]>A*old[i][j]+B)
                {
                    yes=0;
                    break;
                }
        if(yes==1) printf("Yes\n");
        else printf("No\n");
    }
   return 0;
}