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
int a[MX+2];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, s;
    while(cin>>n>>s)
    {
        f(i, 0, n-1)
            cin>>a[i];
        int l = 0, sum = 0, ans = n+2;
        for(int i = 0;i<n;i++)
        {
            sum+=a[i];
            if(sum>=s)
            {
                while(sum>=s)
                {
                    if(sum - a[l]>=s)
                    {
                        sum-=a[l];
                        l++;
                    }
                    else break;
                }
                ans = min(ans, i-l+1);
                sum-=a[l];
                l++;
            }
        }
        if(ans>n)
            ans = 0;
        cout << ans << "\n";
    }
    return 0;
}

