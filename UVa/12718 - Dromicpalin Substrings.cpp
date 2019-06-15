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
ll f[28][1002];
char str[1002];
int main()
{
    fast;
    in;
    //out;
    ll test, cas, cnt, i, j, k, len;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        mem(f, 0);
        cin>>str;
        len = strlen(str);
        for(i=0;i<26;i++)
            f[i][0] = 0;
        for(i=0;i<len;i++)
        {
            f[str[i] - 'a'][i] = 1;
        }
        for(i=1;i<len;i++)
        {
            for(j=0;j<26;j++)
                f[j][i] += f[j][i-1];
        }
        
        cnt = 0;
        for(i=0;i<len;i++)
        {
            for(j=i;j<len;j++)
            {
                if(i==j)
                    cnt++;
                else
                {
                    int odd=0, even=0, c=0;
                    for(k=0;k<26;k++)
                    {
                        c = f[k][j];
                        if(i-1>=0)
                            c-=f[k][i-1];
                        if(c%2==0)
                            even++;
                        else odd++;
                    }
                    if((j-i+1)%2==0 && odd==0)
                        cnt++;
                    else if((j-i+1)%2==1 && odd<=1)
                        cnt++;
                }
            }
        }
        cout << "Case "<< cas << ": " << cnt << "\n";
    }
    return 0;
}