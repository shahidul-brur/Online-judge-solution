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
#define sci(x)          scanf("%d", &x)
#define sci2(x, y)      scanf("%d %d", &x, &y)
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
const int MX = 100002, MOD = 1000000007;
const int INF = 1000000;
vi pos[1005];
int a[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t;
    cin>>t;
    f(cas, 1, t)
    {
        cin>>n>>q;
        f(i, 0, n-1)
        {
            cin>>a[i];
            pos[a[i]].pb(i);
        }
        
        cout << "Case " << cas << "\n";
        f(i, 1, q) 
        {
            int a, b;
            cin>>a>>b;
            int prev = 0, mini = INF;
            f(x, 1, 1000)
            {
                int cnt = upper_bound(all(pos[x]), b) - lower_bound(all(pos[x]), a);
                if(cnt>1)
                {
                    mini = 0;
                    break;
                }
                else if(cnt==1)
                {
                    if(prev!=0)
                        mini = min(mini, x-prev);
                    prev = x;
                }
            }
            cout << mini << "\n";
        }
        f(i, 1, 1000) pos[i].clear();
    }
    return 0;
}

