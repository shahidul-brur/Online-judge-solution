#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ll       long long
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
#define inf             1e9
//             0123456789
const int MX = 1000002;
const ll MOD = 5783568129149;
typedef unsigned long long ull;
int n, m;
ull po[MX+5];
const ull P = 11;
string s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    map<ull, bool> maap;
    po[0] = 1;
    for (int i = 1; i <=MX; ++i) {
        po[i] = (po[i - 1] * P) % MOD;
    }
    
    f(i, 0, n-1)
    {
        cin>>s;
        int len = s.length();
        ll h = 0;
        f(j, 0, len-1)
            h=(h+po[j]*(s[j] - 'a'+1)%MOD)%MOD;
        maap[h] = 1;
    }
    
    f(i, 0, m-1)
    {
        cin>>s;
        int len = s.length();
        bool yes = 0;
        ull h = 0;
        f(j, 0, len-1)
            h = (h + po[j]*(s[j] - 'a'+1)%MOD)%MOD;
        f(j, 0, len-1)
        {
            f(k, 0, 2)
            {
                if(k==s[j]-'a') continue;
                ull hh = (h - po[j]*(s[j] - 'a'+1)%MOD + MOD)%MOD;
                hh = (hh + po[j]*(k+1)%MOD)%MOD;
                if(maap.find(hh)!=maap.end())
                {
                    yes = 1;
                    break;
                }
            }
            if(yes == 1 ) 
                break;
        }
        if(yes)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
