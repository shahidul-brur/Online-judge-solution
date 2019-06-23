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
int f[28], ff[28];
int main()
{
    fast;
    //in;
    //out;
    char n1[102], n2[102], n3[204];
    int len1, len2, len3, i, j;
    cin>> n1>> n2 >> n3;
    len1 = strlen(n1);
    len2 = strlen(n2);
    len3 = strlen(n3);
    int yes = 1;
    if(len3==(len1+len2))
    {
        memset(f, 0, sizeof(f));
        memset(ff, 0, sizeof(ff));
        for(i=0;i<len1;i++)
            f[n1[i] - 'A']++;
        for(i=0;i<len2;i++)
            f[n2[i] - 'A']++;
        for(i=0;i<len3;i++)
            ff[n3[i] - 'A']++;
        for(i=0;i<26;i++)
       {
           if(f[i]!=ff[i])
            {
                yes=0;
                break;
            }
       }
        
    }
    else yes = 0;
    if(yes==1)
        cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}