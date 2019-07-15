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

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 100005;
vector<ll> a;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    ll ans, neg_sum, pos_cnt, pos_sum, x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        neg_sum = pos_sum = pos_cnt = 0LL;
        f(i, 0, n-1)
        {
            cin>>x;
            if(x<0)
            {
                x = -x;
                neg_sum+=x;
                a.pb(x);
            }
            else
            {
                pos_cnt++;
                pos_sum+=x;
            }
        }
        ans = pos_sum * pos_cnt - neg_sum;
        sort(all(a));
        n = a.size();
        f(i, 0, n-1)
        {
            if((pos_sum - a[i])*(pos_cnt+1) - (neg_sum - a[i])>ans)
            {
                pos_sum-=a[i];
                pos_cnt++;
                neg_sum-=a[i];
                ans = pos_sum * pos_cnt - neg_sum;
            }
            else break;
        }
        cout << ans << "\n";
        a.clear();
    }
    return 0;
}

