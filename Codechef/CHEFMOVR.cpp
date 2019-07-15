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
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;
ll ara[MX+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n, d;
        cin>>n>>d;
        ll sum = 0LL;
        f(i, 0, n-1)
            cin>>ara[i], sum+=ara[i];
        if(sum%n!=0) 
        {
            cout << "-1\n";
            continue;
        }
        ll ans = 0LL;
        ll avg = sum/n;
        for(int i=0;i<d;i++)
        {
            sum = 0LL;
            int tot = 0;
            for(int j=i;j<n;j+=d)
            {
                sum+=ara[j];
                tot++;
            }
            if(tot*avg!=sum)
            {
                ans = -1;
                break;
            }
        }
        if(ans==-1)
        {
            cout << ans << "\n";
            continue;
        }
        for(int i=0;i<d;i++)
        {
            ll need = 0LL;
            for(int j=i;j<n;j+=d)
            {
                if(ara[j]<=avg)
                {
                    need+=avg-ara[j];
                    ans+=need;
                }
                else
                {
                    if(need>=ara[j]-avg)
                    {
                        need-=ara[j]-avg;
                        ans+=need;
                    }
                    else
                    {
                        ll extra = (ara[j]-avg) - need;
                        ara[j+d]+=extra;
                        ans+=extra;
                        need = 0LL;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
