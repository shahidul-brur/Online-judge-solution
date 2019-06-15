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
ll len(ll n)
{
    ll s = 0;
    while(n>0)
    {
        n/=2;
        s++;
    }
    return s;
}
int main()
{
    //fast;
    //in;
    //out;
    ll test, a, b, cas, sa, sb, orr, andd;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>a>>b;
        
        /*
        orr = andd = a;
        for(int i=a+1;i<=b;i++)
        {
            orr = orr | i;
            andd = andd & i;
        }
        cout << "#corec: " << orr << " " << andd << "\n";
        
        */
        sb = len(b);
        cout << "Case " << cas << ": " << (ll)(1LL<<sb) - 1 << " ";
        if(a==b)
            cout << a << "\n";
        else 
         {
             sa = len(a);
             if(b - a<=a && a==(ll)(1LL << sa-1))
                cout << a << "\n";
             else cout << "0" << "\n";
         }
         
    }
    return 0;
}
