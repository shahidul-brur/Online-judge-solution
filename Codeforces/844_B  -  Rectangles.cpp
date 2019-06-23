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
const int MX = 100005;
int g[100][100], r[100][3], c[100][3];

ll po(ll p)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll x = po(p/2);
        return 1LL*x*x;
    }
    return 2 * po(p-1);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    f(i, 1, n)
    {
        f(j, 1, m)
        {
            cin>>g[i][j];
        }
    }
    
    f(i, 1, n)
    {
        f(j, 1, m)
        {
            r[i][g[i][j]]++;
        }
    }
    
    f(j, 1, m)
    {
        f(i, 1, n)
        {
            c[j][g[i][j]]++;
        }
    }
    
    ll ans = 1LL * n * m;
    
    //row
    f(i, 1, n)
    {
        int o = r[i][1];
        int z = r[i][0];
        //cout << i << " = " << o << " " << z << "\n";
        if(z>1)
            ans += po(z) - z - 1;
        if(o>1)
            ans += po(o) - o - 1;
    }
    
    //column
    f(i, 1, m)
    {
        int o = c[i][1];
        int z = c[i][0];
        if(z>1)
            ans += po(z) - z - 1;
        if(o>1)
            ans += po(o) - o - 1;
    }
    
    cout << ans << "\n";
    return 0;
}

