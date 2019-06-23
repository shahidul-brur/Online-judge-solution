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
ll a[N+5], cnt[N+5], dp[N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>a[i];
        cnt[a[i]]+=a[i];
    }
    dp[0] = 0;
    dp[1] = cnt[1];  
    
    F(i, 2, 100000)
    {
        dp[i] = max(dp[i-1], dp[i-2]+cnt[i]);
    }
    cout << dp[100000] << "\n";
    return 0;
}

