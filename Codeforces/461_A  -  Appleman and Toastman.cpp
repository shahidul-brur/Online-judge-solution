/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |                                   |
|                                   |
\*=================================*/

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
#define mod 1000000007
#define N 100000
ll a[3*N+5], sum[3*N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    cin>>n;
    F(i, 1, n)
    {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    sort(a, a+n+1);
    F(i, 1, n)
    {
        sum[i] = sum[i-1] + a[i];
    }
    F(i, 0, n-1)
    {
        ans+=a[i];
        ans+=(sum[n]-sum[i]);
        //cout << a[i] << " " << (sum[n]-sum[i]) << "\n";
    }
    cout << ans << "\n";
    return 0;
}

