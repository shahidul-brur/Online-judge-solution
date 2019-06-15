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

int main()
{
    fast;
    in;
    //out;
    long long v1, d1, v2, d2, ut1, dt1, ut2, dt2, g, cas=1, cap, ed, up, down;
    while(cin>>v1>>d1>>v2>>d2)
    {
        if(v1==0 && d1==0 && v2==0 && d2==0)
            break;
        g = gcd(v1, d1);
        ut1 = d1/g;
        dt1 = v1/g;
        
        g = gcd(v2, d2);
        ut2 = d2/g;
        dt2 = v2/g;
        
        cout << "Case #"<< cas++ <<": ";
        
        long long l = lcm(dt1, dt2);
        ed = ut1*(l/dt1);
        cap = ut2*(l/dt2);
        if(cap<ed)
            cap++;
        if(cap>ed)
            cout << "You owe me a beer!" << "\n";
        else cout << "No beer for the captain." << "\n";
        
        cout << "Avg. arrival time: ";
        
        up = dt1 * ut2 + dt2*ut1;
        down = dt1 * dt2 * 2;
        g = gcd(down, up);
        up/=g;
        down/=g;
        if(down==1)
            cout << up << "\n";
        else cout << up << "/" << down << "\n";
    }
    return 0;
}