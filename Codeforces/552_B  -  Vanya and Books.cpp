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
#define vi       vector<ll>
#define vll      vector<ll>
#define ii       pair<ll, ll>
#define vii      vector<pair<ll, ll> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<ll, ll>
#define mli       map<ll, ll>
#define msi       map<string, ll>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(ll i=(a);i<=(b);i++)
#define F(i, a, b)      for(ll i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin>>s)
    {
        ll n = s.length();
        
        if(n==1)
            cout << s << "\n";
        else 
        {
            ll cnt1 = 0;
            ll num = 0;
            for(ll i = 1;i<=n-1;i++)
            {
                num= num*10 + 9;
                
                //cout << num-num/10 << " #\n";
                cnt1+=(num - num/10)*i;
            }
            //cout << cnt1 << " ";
            ll cnt2 = 0;
            ll nine = 0;
            num = 0;
            for(ll j = 0;j<n;j++)
                num = num*10 + s[j] - '0';
            for(ll j = 1;j<n;j++)
                   nine= nine*10 + 9;
            
            cnt2+=(num - nine)*n;
            cout << cnt1 + cnt2 << "\n";
        }
    }
    return 0;
}
