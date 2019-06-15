/************************************************************
* Problem:  UVa 821                                         *
* Link:     http://uva.onlinejudge.org/external/8/821.html  *
* Verdict:  Accepted                                        *
* Date:     2015-09-20                                      *
*                                                           *
* Coder:     Md. Shahidul Islam                             *
* Dept. :    Computer Science and Engineering               *
* Institute: Begum Rokeya University, Rangpur, Bangladesh   *
*  							                                *
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define sq(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
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
#define INF 10000000
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{ 
    fast;
    in;
    //out;
    int pages[103][103], i, j, k, a, b, n, cas=1;
    double sum, total;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;
        for(i=1;i<=101;i++)
            for(j=1;j<=101;j++)
                if(i==j)
                    pages[i][j]=0;
                else 
                    pages[i][j]=INF;
        n=0;
        pages[a][b]=1;
        if(a>n) n=a;
        if(b>n) n=b;
        while(cin>>a>>b)
        {
            if(a==0 && b==0)
                break;
            pages[a][b]=1;
            if(a>n) n=a;
            if(b>n) n=b;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    pages[i][j]=min(pages[i][j], pages[i][k]+pages[k][j]);
        sum=total=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(i!=j && pages[i][j]!=INF)
                {
                    sum+=pages[i][j];
                    total++;
                }
            }
        printf("Case %d: average length between pages = %.3lf clicks\n", cas, sum/total);
        cas++;
    }
    return 0;
}