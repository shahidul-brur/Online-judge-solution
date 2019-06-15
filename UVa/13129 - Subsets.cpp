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
#define sq(a) (a)*(a)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000

ll ar[500005];
ll modPow(ll a, ll p)
{
    if(p==0)
        return 1;
    if(p%2==1)
        return ((a%mod)*(modPow(a, p-1)%mod)%mod);
    else
    {
        ll x = modPow(a, p/2)%mod;
        return (((x%mod)*(x%mod))%mod);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, a, b, q;
    ll ans, p, sum;
    ar[0] = 0;
    while(cin>>n>>p)
    {
        F(i, 1, n)
        {
            cin>>ar[i];
            ar[i]+=ar[i-1];
        }
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            sum = (b-a+2)*(ar[b] - ar[a-1]);
            cout << modPow(p, sum);
            cout << "\n";
        }
        
    }
    return 0;
}

