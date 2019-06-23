#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll P = 257;
const ull MOD = 2305843009213717ull;
const int MX = 1000002;
int n, m;
ull po[MX+5];
unordered_set<ull> hashes;
string s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    po[0] = 1;
    for (int i = 1; i <=MX; ++i) {
        po[i] = (po[i - 1] * P) % MOD;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ull h = 0;
        for (int j = 0; j < s.size(); j++) {
            h = (h + s[j] * po[j] % MOD) % MOD;
        }
        hashes.insert(h);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        ull h = 0;
        for (int j = 0; j < s.size(); j++) {
            h = (h + s[j] * po[j]) % MOD;
        }
        bool found = false;
        for (int j = 0; j < s.size(); j++) 
        {
            for (int ch = 'a'; ch <='c'; ++ch)
            {
                if(s[j]==ch) continue;
                ull hh = (h  - (s[j] * po[j]) % MOD + MOD) % MOD;
                hh = (hh + ch * po[j] % MOD )%MOD;
                if (hashes.find(hh) != hashes.end()) { found = true; break; }
            }
            if(found)
                break;
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
