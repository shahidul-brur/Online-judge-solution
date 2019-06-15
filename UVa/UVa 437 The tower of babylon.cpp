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
//             0123456789
const int MX = 100000;
vector<pair<pair<int, int>, int> > block;
int n;
ll dp[200];
ll cal(int pos)
{
    if(dp[pos]!=-1)
        return dp[pos];
    ll mx = 0;
    f(i, 0, n-1)
    {
        if(block[i].ff.ff<block[pos].ff.ff && block[i].ff.ss<block[pos].ff.ss)
        mx = max(mx, block[i].ss + cal(i));
    }
    return dp[pos] = mx;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n && n>0)
    {
        f(i, 1, n)
        {
            int x, y, z;
            cin>>x>>y>>z;
            block.pb({{x, y}, z});
            block.pb({{y, x}, z});
            block.pb({{z, x}, y});
            block.pb({{x, z}, y});
            block.pb({{z, y}, x});
            block.pb({{y, z}, x});
        }
        mem(dp, -1);
        
        ll mx = 0;
        
        n = block.size();
        f(i, 0, n-1)
        {
            mx = max(mx, block[i].ss+cal(i));
        }
        cout << mx << "\n";
        block.clear();
    }
    return 0;
}

