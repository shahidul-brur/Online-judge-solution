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
int n, x, cnt, ans;
map<char, int> m;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    string ss;
    string t = "Bulbasaur";
    int l = t.length();
    while(cin>>ss)
    {
        m.clear();
        int n = ss.length();
        rep(i, n)
        {
            m[ss[i]]++;
        }
        int B, b, u, a, r, s, l;
        B = m['B'];
        b = m['b'];
        u = m['u'];
        r = m['r'];
        a = m['a'];
        l = m['l'];
        s = m['s'];
        
        ans = B;
        ans = min(ans, b);
        ans = min(ans, u/2);
        ans = min(ans, a/2);
        ans = min(ans, l);
        ans = min(ans, s);
        ans = min(ans, r);
        
        cout << ans << "\n";
    }
    return 0;
}

