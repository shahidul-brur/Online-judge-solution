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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
//             0123456789
const int MX = 5002;
string s;
int cnt[MX][3], n;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>s;
    n = s.length();
    cnt[0][s[0] - 'a'] = 1;
    f(i, 1, n-1)
    {
        cnt[i][0] = cnt[i-1][0];
        cnt[i][1] = cnt[i-1][1];
        cnt[i][s[i] - 'a']++;
    }
    int ans = 0;
    ans = max(ans, cnt[n-1][0]);
    ans = max(ans, cnt[n-1][1]);
    // 2 part
    f(i, 1, n-1)
    {
        ans = max(ans, cnt[i-1][0]+(cnt[n-1][1] - cnt[i-1][1]));
        ans = max(ans, cnt[i-1][1]+(cnt[n-1][0] - cnt[i-1][0]));
    }
    f(i, 0, n-1)
    {
        f(j, i+1, n-2)
        {
            ans = max(ans, cnt[i][0]+(cnt[j][1] - cnt[i][1])+
                      + (cnt[n-1][0] - cnt[j][0]));
        }
    }
    cout << ans << "\n";
    return 0;
}

