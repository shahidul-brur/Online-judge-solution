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
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
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
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{
    fast;
    //in;
    //out;
    int n, row1[55], row2[55], cross[55], total, mini, i, j, k, sum1[55], sum2[55], t2;
    while(cin>>n)
    {
        row1[0]= row2[0] = sum1[0] = sum2[n-1] = 0;
        
        for(i=1;i<n;i++)
        {
            cin>>row1[i];
            sum1[i]=sum1[i-1] + row1[i];
        }
        
        for(i=1;i<n;i++)
        {
            cin>>row2[i];
        }
        
        for(i=n-2;i>=0;i--)
        {
            sum2[i] = sum2[i+1] + row2[i+1];
        }
        
        for(i=0;i<n;i++)
        {
            cin>>cross[i];
        }
        
        mini = 1000000000;
        
        for(i=0;i<n;i++)
        {
            total = sum2[i] + cross[i] + sum1[i];
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    t2 = sum1[j] + cross[j] + sum2[j];
                    if(total+t2<mini)
                        mini = total+t2;
                }
            }
        }
        cout << mini << "\n";
    }
    return 0;
}