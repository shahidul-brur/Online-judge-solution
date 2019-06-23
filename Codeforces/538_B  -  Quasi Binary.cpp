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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 1000000;
vi opt;
int dp[MAX+5], pre[MAX+5], val[MAX+5];
void calOpt()
{
    for(int i = 1;i<=64;i++)
    {
        int p = 1;
        int now = i;
        int num = 0;
        string s;
        while(now>0)
        {
            s+=(now%2)+'0';
            now/=2;
        }
        int l = s.length();
        repba(j, l-1, 0)
        {
            num = num*10 + s[j] - '0';
        }
        opt.pb(num);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    calOpt();
    for(int i = 0;i<64;i++)
        dp[opt[i]] = 1, val[opt[i]] = opt[i];
    int n;
    while(cin>>n)
    {
        for(int i = 1;i<=n;i++)
        {
            if(dp[i]==0)
            {
                int mini = MAX+500;
                int p;
                for(int j = 0;j<64;j++)
                {
                    if(i > opt[j] && dp[i-opt[j]]+1<mini)
                        mini = dp[i-opt[j]]+1, p = opt[j];
                    
                }
                dp[i] = mini;
                pre[i] = i - p;
                val[i] = p;
            }
        }
        cout << dp[n] << "\n";
        while(n>0)
        {
            cout << val[n] << " ";
            n = pre[n];
        }
        cout << "\n";
    }
    return 0;
}