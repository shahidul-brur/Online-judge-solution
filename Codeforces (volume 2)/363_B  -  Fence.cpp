#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int h, n, i, j;
    int dp[200005], k;
    while(cin>>n>>k)
    {
        dp[0] = 0;
        F(i, 1, n)
        {
            cin>>h;
            dp[i] = dp[i-1]+h;
        }
        int ans = 1;
        int sum = 1e9;
        for(i=1;n-i+1>=k;i++)
        {
            if(dp[i+k-1]-dp[i-1]<sum)
            {
                sum = dp[i+k-1]-dp[i-1];
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
