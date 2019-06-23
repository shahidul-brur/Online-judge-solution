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
int ara[MX+5];
int mini[MX+5];
int maxi[MX+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin>>n>>k)
    {
        f(i, 1, n) cin>>ara[i];
        int mx = ara[1];
        int mn = ara[1];
        int p = 1;
        f(i, 2, n) 
        {
            if(ara[i]>mx)
            {
                mx = ara[i];
                p = i;
            }
            mn = min(mn, ara[i]);
        }
        if(k==1)
        {
            cout << mn << "\n";
        }
        else if(k==2)
        {
            if(p==1 || p==n)
                cout << mx << "\n";
            else 
            {
                mini[1] = ara[1];
                maxi[n] = ara[n];
                f(i, 2, n)
                {
                    mini[i] = min(mini[i-1], ara[i]);
                }
                F(i, n-1, 1)
                {
                    maxi[i] = min(maxi[i+1], ara[i]);
                }
                int ans = max(mini[1], maxi[2]);
                f(i, 2, n-1)
                {
                    ans = max(ans, max(mini[i], maxi[i+1]));
                }
                cout << ans << "\n";
            }
        }
        else if(k>=3)
            cout << mx << "\n";
    }
    return 0;
}