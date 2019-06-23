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
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, n) for(ll i=0;i<n;i++)
#define FOR(i, b, a) for(int i=b;i>=a;i--)
#define sq(a) (a)*(a)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define N 200005
ll n, k, m, x, s;
ll c1[N], t1[N],  c2[N], cr2[N];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    while(cin>>n>>m>>k)
    {
        cin>>x>>s;
        rep(i, m) cin>>t1[i];
        rep(i, m) cin>>c1[i];
        rep(i, k) cin>>cr2[i];
        rep(i, k) cin>>c2[i];
        cr2[k] = 0;
        
        ll mini = n*x;
        rep(i, m)
            if(c1[i]<=s)
            {
                ll rem = s - c1[i];
                ll rn = n - cr2[upper_bound(c2, c2+k, rem) - c2-1];
                mini = min(mini, rn*t1[i]);
            }
        mini = min(mini, (n-cr2[upper_bound(c2, c2+k, s) - c2-1])*x);
        cout << mini << "\n";
    }
    return 0;
}


