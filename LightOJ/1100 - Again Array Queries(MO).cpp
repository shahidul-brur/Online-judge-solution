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
const int INF = 1000000, sqr = 17;
vector<pair<pii , int> > queries;
int a[MX], ans[10005];
int cnt[1005];
bool cmp(pair<pii , int> a, pair<pii , int> b)
{
    if(a.ff.ff/sqr == b.ff.ff/sqr)
        return a.ff.ss<b.ff.ss;
    return a.ff.ff/sqr < b.ff.ff/sqr;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t;
    scanf("%d", &t);
    f(cas, 1, t)
    {
        scanf("%d", &n);
        scanf("%d", &q);
        f(i, 1, n)
        {
            scanf("%d", &a[i]);;
        }
        
        printf("Case %d:\n", cas);
        
        f(i, 0, q-1) 
        {
            int a, b;
            scanf("%d %d", &a, &b);
            queries.pb({{++a, ++b}, i});
        }
        sort(all(queries), cmp);
        mem(cnt, 0);
        int lft=1, rgt = 0;
        //cnt[a[0]]++;
        
        f(i, 0, q-1) 
        {
            int l = queries[i].ff.ff;
            int r = queries[i].ff.ss;
            int idx = queries[i].ss;
            
            while(rgt<r)
            {
                cnt[a[++rgt]]++;
            }
            while(rgt>r)
            {
                cnt[a[rgt--]]--;
            }
            while(lft<l)
            {
                cnt[a[lft++]]--;
            }
            while(lft>l)
            {
                cnt[a[--lft]]++;
            }
            
            int last = -1, mini = 1000000;
            f(j, 1, 1000)
            {
                if(cnt[j]>1)
                {
                    mini = 0;
                    break;
                }
                else if(cnt[j]==1)
                {
                    if(last!=-1)
                        mini = min(mini, j-last);
                    last = j;
                }
            }
            ans[idx] = mini;
        }
        f(i, 0, q-1)
        {
            printf("%d\n",ans[i]);
        }
        queries.clear();
    }
    return 0;
}
