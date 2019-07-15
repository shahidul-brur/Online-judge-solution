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
#define F(i, a, b) for(int i=a;i<=b;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int dp[100005][105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, k, n, m, t, i, j;
    cin>>t;
    while(t--)
    {
        string s, w;
        cin>>s>>w;
        cin>>a>>b>>k;
        m = s.size();
        n = w.size();
        if(s==w)
            cout << "0\n";
        else if(abs(m-n)>k || k==0)
            cout << "-1\n";
        else 
        {
            dp[0][0] = 0;
            for(i=1;i<=m;i++)
                dp[i][0] = a*k;
            for(i=1;i<=k;i++)
                dp[0][i] = a*k;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=k;j++)
                {
                    if(s[i] == w[j])
                        dp[i][j] = dp[i-1][j-1];
                    else
                    {
                        dp[i][j] = min(dp[i-1][j-1]+a, min(dp[i-1][j]+b, dp[i][j-1]+a));
                    }
                    if(dp[i][j]>k)
                        break;
                }
            }
            
        }
    }
    return 0;
}


