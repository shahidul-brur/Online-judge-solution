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
const int MX = 200005, MOD = 1000000007;
const int INF = (int)1e9;
pair<int, int> a[MX], b[MX];
int ans[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        f(i, 0, n-1)
        {
            cin>>a[i].first;
            a[i].second = i;
        }
        f(i, 0, n-1)
        {
            cin>>b[i].first;
            b[i].second = i;
        }
        
        sort(a, a+n);
        sort(b, b+n);
        
        for(int i = 0, j = n-1;i<n;i++, j--)
        {
            ans[b[i].second] = a[j].first;            
        }
        f(i, 0, n-1)
        {
            if(i>0)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
