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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    ll l1, r1, l2, r2, k, ans;
    while(cin>>l1>>r1>>l2>>r2>>k)
    {
        if(l2>r1 || l1>r2)
            ans = 0LL;
        else
        {
            ll from = max(l1, l2);
            ll to = min(r1, r2);
            ans = to - from + 1;
            if(k>=from && k<=to)
                ans--;
            if(ans < 0)
                ans = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}


