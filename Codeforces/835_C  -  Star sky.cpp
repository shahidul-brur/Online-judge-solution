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
const int MX = 100002;
const int MOD = 1000000007;
const int INF = (int)1e9;
int cnt[12][105][105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, x, y, s, tim, x1, y1, c;
    while(cin>>n>>q>>c)
    {
        f(i, 0, n-1)
        {
            cin>>x>>y>>s;
            cnt[s][x][y]++;
        }
        f(i, 0, c)
            f(j, 1, 100)
                f(k, 1, 100)
                    cnt[i][j][k]+=cnt[i][j][k-1];
        while(q--)
        {
            int ans = 0;
            cin>>tim>>x>>y>>x1>>y1;
            f(i, 0, c)
            {
                f(j, x, x1)
                {
                    ans+=(cnt[i][j][y1] - cnt[i][j][y-1])*((i+tim)%(c+1));
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}


