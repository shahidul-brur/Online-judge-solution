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
int n;
struct road
{
    double d;
    int g, y, r;
}stopage[10];
bool isRed(int v)
{
    for(int i=0;i<n;i++)
    {
        if(stopage[i].r>0)
        {
            double s = stopage[i].d;
            int t = s*3600/v;
            int rem = t%(stopage[i].g + stopage[i].y + stopage[i].r);
            if(rem>0 && rem >= stopage[i].g + stopage[i].y)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    //fast;
    in;
    //out;
    int speed[65], acc, i, cas=1, j;
    while(cin>>n)
    {
        if(n==-1)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>stopage[i].d>>stopage[i].g>>stopage[i].y>>stopage[i].r;
        }
        for(i=30;i<=60;i++)
            speed[i] = 0;
        acc = 0;
        for(i=30;i<=60;i++)
        {
            if(!isRed(i))
            {
                speed[i] = 1;
                acc++;
            }
        }
        cout << "Case " << cas++ << ":";
        if(acc == 0)
        {
            cout << " No acceptable speeds.\n";
        }
        else
        {
            int p = 0;
            for(i=30;i<=60;)
            {
                if(speed[i] == 1)
                {
                    if(p>0)
                        cout << ",";
                    cout << " " << i;
                    if(speed[i+1] == 1)
                    {
                        cout << "-";
                        for(j=i+2;j<=61;j++)
                        {
                            if(speed[j]==0)
                            {
                                cout << j-1;
                                i=j;
                                break;
                            }
                        }
                    }
                    else i++;
                    p++;
                }
                else i++;
            }
            cout << "\n";
        }
    }
    return 0;
}