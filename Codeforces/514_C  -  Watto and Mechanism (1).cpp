#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define f(i, a, b) for(int i = (a);i<=(b);i++)
#define ll long long
const int MX = 1000002;
const long long MOD = 5783568129149;
typedef unsigned long long ull;
int n, m;
ull po[MX+5];
const ull P = 31;
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