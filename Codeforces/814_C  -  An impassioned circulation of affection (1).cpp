#include<bits/stdc++.h>
using namespace std;
#define f(i, a, b) for(int i=(a);i<=(b);i++)
int cnt[27][1505];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n, q, m;
    char c;
    cin>>n;
    cin>>s;
    f(i, 0, 25)
    {
        f(j, 0, n-1)
        {
            int tot = 0;
            int need = 0;
            f(k, j, n-1)
            {
                tot++;
                if(s[k] - 'a' != i)
                    need++;
                cnt[i][need] = max(cnt[i][need], tot);
            }
        }
        f(j, 1, n)
            cnt[i][j] = max(cnt[i][j], cnt[i][j-1]);
    }
    cin>>q;
    while(q--)
    {
        cin>>m>>c;
        cout << cnt[c-'a'][m] << "\n";
    }
    return 0;
}
