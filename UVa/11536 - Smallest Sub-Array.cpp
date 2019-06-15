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
const int MX = 1000000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;
int a[MX+2], f[102];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, t;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    cin>>t;
    
    f(cas, 1, t)
    {
        cin>>n>>m>>k;
        mem(f, 0);
        f(i, 4, n)
        {
            a[i] = (a[i-1]+a[i-2]+a[i-3])%m + 1;
        }
        int l = 1, ans = n+1, cnt = 0;
        f(i, 1, n)
        {
            if(a[i]<=k)
            {
                if(f[a[i]]==0)
                    cnt++;
                f[a[i]]++;
                if(cnt==k)
                {
                    while(1)
                    {
                        if(a[l]>k)
                            l++;
                        else if(f[a[l]]>1)
                        {
                            f[a[l]]--;
                            l++;
                        }
                        else break;
                    }
                    ans = min(ans, i-l+1);
                }
            }
        }
        cout << "Case " << cas << ": ";
        if(ans>n)
            cout << "sequence nai\n";
        else cout << ans << "\n";
    }
    return 0;
}


