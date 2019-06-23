/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
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
int dp[105], dp_without_d[105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, d;
    cin>>n>>k>>d;
    F(i, 1, k)
    {
        dp[i]=1;
        if(i<d)
            dp_without_d[i] = 1;
    }
    F(i, 1, n)
    {
        F(j, 1, min(i, k))
        {
            dp[i]=(dp[i]+dp[i-j])%mod;
            if(j<d)
                dp_without_d[i] = (dp_without_d[i]+dp_without_d[i-j])%mod;
        }
    }
    cout << (dp[n] - dp_without_d[n]+mod)%mod << "\n";
    return 0;
}