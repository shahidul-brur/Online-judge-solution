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
int dp[100009];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, j, q, l, r;
    string s;
    cin>>s;
    n = s.length();
    dp[0] = 0;
    F(i, 0, n-2)
    {
        if(s[i]==s[i+1])
            dp[i+1] = dp[i]+1;
        else dp[i+1] = dp[i];
        //cout << i+1 << " : " << dp[i+1] << " \n";
    }
    dp[n] = dp[n-1];
    cin>>q;
    while(q-->0)
    {
        cin>>l>>r;
        cout << dp[r-1] - dp[l-1] << "\n";
    }
    return 0;
}

