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
    //fast;
    in;
    //out;
    int test, cas, orig[5], opened[5], posi, i, j, s, start[6];
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>orig[0]>>orig[1];
        cin>>orig[3]>>orig[2];
        
        cin>>opened[0]>>opened[1];
        cin>>opened[3]>>opened[2];
        
        posi = 1;
        int found = 0;
        s=0;
        for(i=0;i<4;i++)
        {
            if(opened[i] == orig[0])
            {
                start[s++] = i;
            }
        }
        for(int k=0;k<s;k++)
        {
            i=start[k];
            found = 1;
            for(int j = 0;j<4;j++)
            {
                if(opened[i%4] != orig[j])
                {
                    found = 0;
                    break;
                }
                else
                {
                    i++;
                }
            }
            if(found==1)
                break;
        }
        if(found == 0)
            posi = 0;
            
        if(posi==0)
            cout << "Case #" << cas << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << cas << ": POSSIBLE\n"; 
    }
    return 0;
}