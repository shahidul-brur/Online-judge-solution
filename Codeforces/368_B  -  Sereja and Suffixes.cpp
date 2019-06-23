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
int dp[N+5];
bool p[N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, m, l, x, a[N+5];
    cin>>n>>m;
    dp[n+1] = 0;
    F(i, 1, n)
    {
        cin>>a[i];
    }
    
    Fr(i, n, 1)
    {
        x = a[i];
        if(p[x]==0)
        {
            dp[i] = dp[i+1] + 1;
            p[x] = 1;
        }
        else dp[i] = dp[i+1];
    }
    F(i, 1, m)
    {
        cin>>l;
        cout << dp[l] << "\n";
    }
    return 0;
}

