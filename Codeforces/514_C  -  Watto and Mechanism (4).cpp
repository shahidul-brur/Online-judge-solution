#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll P = 11;
const ll MOD1 = 1e9+7;
const ll MOD2 = 1e9+9;
const int MX = 600002;
int n, m;
ll po1[MX+5];
ll po2[MX+5];
set<pair<ll, ll> > hashes;
string s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    po1[0] = 1;
    po2[0] = 1;
    for (int i = 1; i <=MX; ++i) {
        po1[i] = (po1[i - 1] * P) % MOD1;
        po2[i] = (po2[i - 1] * P) % MOD2;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ll h1 = 0;
        ll h2 = 0;
        for (int j = 0; j < s.size(); j++) {
            h1 = (h1 + s[j] * po1[j] % MOD1) % MOD1;
            h2 = (h2 + s[j] * po2[j] % MOD2) % MOD2;
        }
        hashes.insert({h1, h2});
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        ll h1 = 0;
        ll h2 = 0;
        for (int j = 0; j < s.size(); j++) {
            h1 = (h1 + s[j] * po1[j] % MOD1) % MOD1;
            h2 = (h2 + s[j] * po2[j] % MOD2) % MOD2;
        }
        bool found = false;
        for (int j = 0; j < s.size(); j++) 
        {
            for (int ch = 'a'; ch <='c'; ++ch)
            {
                if(s[j]==ch) continue;
                ll hh1 = (h1  - (s[j] * po1[j]) % MOD1 + MOD1) % MOD1;
                hh1 = (hh1 + ch * po1[j] % MOD1)%MOD1;
                
                ll hh2 = (h2  - (s[j] * po2[j]) % MOD2 + MOD2) % MOD2;
                hh2 = (hh2 + ch * po2[j] % MOD2 )%MOD2;
                
                if (hashes.find({hh1,hh2}) != hashes.end()) { found = true; break; }
            }
            if(found)
                break;
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
