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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
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
    ll n, x, ans;
    while(cin>>n>>x)
    {
        ll pos = n%6;
        if(pos==0)
        {
            ans = x;
        }
        else if(pos==1)
        {
            if(x==0)
                ans = 1;
            else if(x==1)
                ans = 0;
            else ans = 2;
        }
        else if(pos==2)
        {
            if(x==0)
                ans = 1;
            else if(x==1)
                ans = 2;
            else ans = 0;
        }
        else if(pos==3)
        {
            if(x==0)
                ans = 2;
            else if(x==1)
                ans = 1;
            else ans = 0;
        }
        else if(pos==4)
        {
            if(x==0)
                ans = 2;
            else if(x==1)
                ans = 0;
            else ans = 1;
        }
        else if(pos==5)
        {
            if(x==0)
                ans = 0;
            else if(x==1)
                ans = 2;
            else ans = 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
