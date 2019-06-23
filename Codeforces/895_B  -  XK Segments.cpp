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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
//             0123456789
const int MX = 100005;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll x, k;
    while(cin>>n>>x>>k){
        vector<ll> a;
        f(i, 0, n-1)
        {
            ll num;
            cin>>num;
            a.pb(num);
        }
        ll ans = 0LL;
        sort(all(a));
        f(i, 0, n-1){
            if(k==0 && a[i]%x==0)
                continue;
            
            ll d = (a[i]-1)/x;
            ll fst = 1LL*(d+k)*x;
            ll lst = 1LL*(d+k+1)*x;
            if(fst<a[i])
                fst = a[i];
            auto it = lower_bound(all(a), fst);
            auto it2 = lower_bound(all(a), lst);
            ll leq = it2 - it;
            //cout << a[i] << ": " << fst << ", " << lst << " "<< leq << "\n";
            ans+=leq;
        }
        cout << ans << "\n";
    }
    return 0;
}

