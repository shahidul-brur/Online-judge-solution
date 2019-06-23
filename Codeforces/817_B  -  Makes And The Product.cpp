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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a[MX+2];
    map<int, int> cnt;
    while(cin>>n)
    {
        f(i, 0, n-1)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        sort(a, a+n);
        if(a[0]==a[1] && a[1]==a[2])
        {
            ll x = cnt[a[0]];
            cout << 1LL * x * (x-1) * (x-2)/6LL << "\n";
        }
        else if(a[0]!=a[1] && a[1]==a[2])
        {
            ll x = cnt[a[1]];
            cout << 1LL * x * (x-1)/2LL << "\n"; 
        }
        else
        {
            cout << cnt[a[2]] << "\n"; 
        }
        cnt.clear();
    }
    return 0;
}

