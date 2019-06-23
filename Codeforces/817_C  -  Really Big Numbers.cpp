/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;

bool isPossible(ll val, ll s)
{
    ll sum = 0LL, x = val;
    while(val>0)
    {
        sum+=val%10;
        val/=10;
    }
    //cout << x << " : " << sum << "\n";
    return (x - sum>=s);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, s, mini;
    while(cin>>n>>s)
    {
        ll l = 1, r = n, ans;
        mini=-1;
        while(l<=r)
        {
            ll mid = (l+r)/2LL;
            if(isPossible(mid,s))
            {
                mini  = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(mini==-1)
            ans = 0LL;
        else ans = n - mini+1;
        
        //cout << mini << " -> ";
        cout << ans << "\n";
    }
    return 0;
}

