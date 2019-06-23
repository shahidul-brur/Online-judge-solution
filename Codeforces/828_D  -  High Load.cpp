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
const int MX = 200010;
const int MOD = 1000000007;
const int INF = (int)1e9;
vii ans;
int point[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, edge = 0, i;
    cin>>n>>k;
    for(i=2;i<=k+1;i++)
    {
        ans.pb({1, i});
        point[i-1] = i;
        edge++;
    }
    int now = n+1 , lev=1;
    while(edge<n-1)
    {
        if(now>k)
        {
            now = 1;
            lev++;
        }
        ans.pb({point[now], i});
        point[now] = i;
        i++;
        now++;
        edge++;
    }
    now--;
    if(now>=2)
        cout << 2*lev << "\n";
    else if(now==1)
        cout << 2*lev - 1 << "\n";
    f(j, 0, n-2)
        cout << ans[j].ff << " " << ans[j].ss << "\n";
    return 0;
}
