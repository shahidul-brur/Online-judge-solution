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

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 1000005;
ll x, y, p, q;
bool isOk(ll d)
{
    if(d*q<y)
        return 0;
    ll up = p*d - x;
    ll down = q*d - y;
    if(up>=0 && up<=down)
        return 1;
    else return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>p>>q;
        if((ll)x*q*1LL==(ll)y*p*1LL)
        {
            cout << "0\n";
        }
        else
        {
            ll ans = 1100000000000000000 * 1LL;
            //cout << ans << "# ";
            ll l = y/q + 1;
            ll r = 1000000000 * 1LL;
            while(l<=r)
            {
                ll mid = (ll)(l+r)/2;
                if(isOk(mid))
                {
                    ans = min(ans, mid);
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            if(ans==1100000000000000000*1LL)
                cout << "-1\n";
            else cout << ans*q - y << "\n";
        }
    }
    return 0;
}
