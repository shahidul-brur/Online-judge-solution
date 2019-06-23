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
const int MX = 200005;
const int INF = INT_MAX;
vii l[MX], r[MX];
vi miniL[MX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, a, b, c;
    while(cin>>n>>x)
    {
        f(i, 1, n)
        {
            cin>>a>>b>>c;
            
            r[b-a+1].pb(mp(c, b));
            l[b-a+1].pb(mp(a, c));
        }
        
        f(i, 1, MX-5)
        {
            int s = l[i].sz;
            if(s>0)
            {
                sort(all(l[i]));
                miniL[i].resize(s);
                
                int mini = l[i][s-1].ss;
                
                F(j, s-1, 0)
                {
                    mini = min(mini, l[i][j].ss);
                    miniL[i][j] = mini;
                }
            }
            
            s = r[i].sz;
            if(s>0)
            {
                sort(all(r[i]));
            }
        }
        
        int ans = INF;
        
        f(i, 1, x-1)
        {
            int s = r[i].sz;
            if(l[x-i].sz>0)
                f(j, 0, s-1)
                {
                    int lb = lower_bound(all(l[x-i]), mp(r[i][j].ss+1, 0)) - l[x-i].begin();
                    if(lb<l[x-i].sz)
                    {
                        //cout << i << " : " << r[i][j].ss << " = " << lb << " , " << l[x-i][lb].ff << "\n";
                        int cur = r[i][j].ff+miniL[x-i][lb];
                        if(cur<ans)
                        {
                            ans = cur;
                        }
                    }
                }
        }
        if(ans==INF)
            cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}

