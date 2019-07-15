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
#define inf             1e9
const int MX = 100005;
const ll mod = 1000000007;
int p, q, r, t;
ll x[MX], y[MX], z[MX];
ll cx[MX], cz[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>p>>q>>r;
        cx[0] = cz[0] = 0LL;
        f(i, 1, p)
        {
            cin>>x[i];
            //x[i] = x[i]%mod;
        }
        sort(x+1, x+p+1);
        
        f(i, 1, q)
        {
            cin>>y[i];
            //y[i] = y[i]%mod;
        }
        sort(y+1, y+q+1);
        
        f(i, 1, r)
        {
            cin>>z[i];
            //z[i] = z[i]%mod;
        }
        sort(z+1, z+r+1);
        
        f(i, 1, p)
        {
            cx[i] = (cx[i-1]%mod + x[i]%mod)%mod;
        }
        
        f(i, 1, r)
        {
            cz[i] = (cz[i-1]%mod + z[i]%mod)%mod;
        }
        
        ll ans = 0LL;
        
        f(i, 1, q)
        {
            ll idx = upper_bound(x+1, x+p+1, y[i]) - x;
            ll idz = upper_bound(z+1, z+r+1, y[i]) - z;
            
            if(idz>r || z[idz]>y[i])
                idz--;
            if(idx>p || x[idx]>y[i])
                idx--;
            if(idx==0 || idz==0)
                continue;
            ans = ans%mod + (cz[idz]*cx[idx])%mod + (((1LL*idz*(y[i]%mod))%mod)*cx[idx])%mod;
            ans = ans%mod + ((( (((1LL*idz*1LL*idx)%mod) * (y[i]%mod))%mod) * (y[i]%mod))%mod)%mod;
            ans = ans%mod + (((1LL*idx*cz[idz])%mod)*(y[i]%mod))%mod;
            ans%=mod;
        }
        cout << ans << "\n";
    }
    return 0;
}

