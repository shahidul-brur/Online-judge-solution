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
char xNow[10002], xNext[10002], temp[10002];
int main()
{
    fast;
    //in;
    //out;
    int term, digit, i, j, k, ans, len, repeat, index;
    while(cin>>xNow>>term>>digit)
    {
        if(xNow[0]=='0' && term==0 && digit==0)
            break;
        if(term==1)
            ans = xNow[digit-1] - '0';
        else
        {
            for(i=2;i<=term;i++)
            {
                len = strlen(xNow);
                index = 0;
                for(j=0;j<len && j<=digit;)
                {
                    repeat = 1;
                    for(k=j+1;k<len;k++)
                    {
                        if(xNow[k]==xNow[j])
                            repeat++;
                        else break;
                    }
                    sprintf(temp, "%d", repeat);
                    strcpy(xNext+index, temp);
                    index += strlen(temp);
                    xNext[index] = xNow[j];
                    xNext[index+1] = '\0';
                    if(digit+5<index+1)
                    {
                        xNext[digit+5] = '\0';
                        break;
                    }
                    index++;
                    j=k;
                }
                strcpy(xNow, xNext);
                strcpy(xNext, "");
            }
            ans = xNow[digit-1] - '0';
        }
        cout << ans << "\n";
    }
    return 0;
}