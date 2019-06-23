#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll prime = 257;
const ull mod = 2305843009213717ull;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    unordered_set<ull> hashes;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ull h = 0, pp = 1;
        for (int j = 0; j < s.size(); j++) {
            h = (h + s[j] * pp % mod) % mod;
            pp = (pp * prime) % mod;
        }
        hashes.insert(h);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        ull h = 0, pp = 1;
        for (int j = 0; j < s.size(); j++) {
            h = (h + s[j] * pp) % mod;
            pp = (pp * prime) % mod;
        }

        pp = 1;
        bool found = false;
        for (int j = 0; j < s.size(); j++) {
            char fst = 'a',
                 snd = 'b';

            if (s[j] == 'a') fst = 'c';
            else if (s[j] == 'b') snd = 'c';

            ull nh = (h  - (s[j] * pp) % mod + mod) % mod;
            ull a = (nh + fst * pp % mod) % mod;
            ull b = (nh + snd * pp % mod) % mod;

            if (hashes.find(a) != hashes.end()) { found = true; break; }
            if (hashes.find(b) != hashes.end()) { found = true; break; }

            pp = (pp * prime) % mod;
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}