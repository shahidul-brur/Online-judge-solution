/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rrep(i, k)      for(int i=k-1;i>=0;i--)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1000005
#define inf             1e9

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    vi ans;
    string s;
    while(cin>>n>>s)
    {
        rep(i, n)
        {
            if(s[i]=='2' || s[i]=='3' || s[i]=='5' || s[i]=='7')
                ans.pb(s[i] - '0');
                
            else if(s[i]=='4')
                ans.pb(2), ans.pb(2), ans.pb(3);
            else if(s[i]=='6')
                ans.pb(3), ans.pb(5);
            else if(s[i]=='8')
                ans.pb(2), ans.pb(2), ans.pb(2), ans.pb(7);
            else if(s[i]=='9')
                ans.pb(3), ans.pb(2), ans.pb(3), ans.pb(7);
        }
        sort(all(ans));
        int n = ans.sz;
        rrep(i, n)
            cout << ans[i];
    }
    return 0;
}

