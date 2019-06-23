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
int a[55][55], n;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n)
    {
        f(i, 1, n) f(j, 1, n) cin>>a[i][j];
        bool y = 1;
        f(i, 1, n) 
        {
            f(j, 1, n)
            {
                if(a[i][j]==1)
                    continue;
                bool ok = 0;
                f(k, 1, n) 
                {
                    f(l, 1, n)
                    {
                        if(a[k][j]+a[i][l]==a[i][j])
                        {
                            ok = 1;
                            break;
                        }
                    }
                    if(ok)
                        break;
                }
                if(!ok)
                {
                    y = 0;
                    break;
                }
            }
            if(!y)
                break;
        }
        if(y)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

