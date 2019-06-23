/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define FR(i, a, b) for(int i=a;i<=b;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
ll dp[210][210];
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test, cas, n;
    vector<ll> a[210];
    cin>>test;
    FR(cas, 1, test)
    {
        cin>>n;
        FR(i, 1, n)
        {
            FR(j, 1, i)
            {
                ll x;
                cin>>x;
                a[i].pb(x);
            }
        }
        int k=1;
        FR(i, n+1, 2*n-1)
        {
            FR(j, 1, n-k)
            {
                ll x;
                cin>>x;
                a[i].pb(x);
            }
            k++;
        }
        
        dp[1][0] = a[1][0];
        a[1].clear();
        FR(i, 2, n)
        {
            FR(j, 0, i-1)
            {
                if(j==0)
                    dp[i][j] = a[i][j] + dp[i-1][j];
                if(j==i-1)
                    dp[i][j] = a[i][j] + dp[i-1][j-1];
                else 
                    dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                //cout << dp[i][i] << " ";
            }
            a[i].clear();
            //cout << "\n";
        }
        k = 1;
        FR(i, n+1, 2*n-1)
        {
            FR(j, 0, n-k-1)
            {
                dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                //cout << dp[i][i] << " ";
            }
            a[i].clear();
            k++;
        }
        
        cout << "Case " << cas << ": " << dp[2*n-1][0] << "\n";
    }
    return 0;
}


