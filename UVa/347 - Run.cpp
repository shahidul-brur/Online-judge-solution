/************************************************************
* Problem:   
* Link:                                                     
* Verdict:  Accepted 
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
int digit[10], d;
void spanDigit(int n)
{
    d = 0;
    int a[10];
    while(n>0)
    {
        a[d++] = n%10;
        n/=10;
    }
    for(int i=0, j=d-1;i<d;i++, j--)
    {
        digit[i] = a[j];
    }
}
bool isRun(int n)
{
    spanDigit(n);
    int rep[11];
    for(int i=0;i<=9;i++)
        rep[i] = 0;
    for(int i=0;i<d;i++)
        rep[digit[i]]++;
    if(rep[0]>0)
        return 0;
    for(int i=0;i<=9;i++)
        if(rep[i]>1)
            return 0;
    int used = 0, last;
    int usedIndex[10];
    for(int i=0;i<=d;i++)
        usedIndex[i] = 0;
    for(int i=0;i<d;)
    {
        used++;
        usedIndex[i] = 1;
        int now = i;
        for(int j=1;j<=digit[now];j++)
        {
            i++;
            if(i>=d)
                i = 0;
        }
        if(usedIndex[i] == 1 && used<d)
        {
            return 0;
        }
        if(used==d)
        {
            last = i;
            break;
        }
    }
    if(last == 0)
        return 1;
    else return 0;
}
int main()
{
    //fast;
    in;
    //out;
    int n, i, cas=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        
        for(i=n;;i++)
        {
            if(isRun(i))
            {
                cout << "Case " << cas++ << ": " << i << "\n";
                break;
            }
        }
    }
    return 0;
}