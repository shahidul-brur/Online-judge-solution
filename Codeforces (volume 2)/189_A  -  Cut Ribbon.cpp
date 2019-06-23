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
#define N 1000000
int dp[4005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, len;
    cin>>n;
    F(i, 1, 3)
    {
        cin>>len;
        F(j, len, n)
        {
            if(dp[j-len]>0 || j==len)
                dp[j] = max(dp[j], dp[j-len]+1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}

