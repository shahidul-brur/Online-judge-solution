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
#define rep(i, n) for(i = 0; i < n; i++)
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
int a[1005][1005];
int main()
{
    //fast;
    //in;
    //out;
    int i, j, r, c, mov, n, m;
    cin>>n>>m>>mov;
    int f = 0;
    mem(a, 0);
    for(int s=1;s<=mov;s++)
    {
        cin>>r>>c;
        a[r][c] = 1;
        if(a[r-1][c-1]==1 && a[r-1][c]==1 && a[r][c-1]==1 && f==0)
        {
            cout << s << "\n";
            f=1;
        }
        else if(a[r-1][c]==1 && a[r-1][c+1]==1 && a[r][c+1]==1 && f==0)
        {
            cout << s << "\n";
            f=1;
        }
        else if(a[r][c-1]==1 && a[r+1][c-1]==1 && a[r+1][c]==1 && f==0)
        {
            cout << s << "\n";
            f=1;
        }
        else if(a[r][c+1]==1 && a[r+1][c+1]==1 && a[r+1][c]==1 && f==0)
        {
            cout << s << "\n";
            f=1;
        }
    }
    if(f==0)
        cout << "0\n";
    return 0;
}