#include<bits/stdc++.h>
using namespace std;
#define MX 300005
const int mod = 1e9 + 7;
#define ll long long
int a[MX], p2[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    p2[0] = 1;
    for(int i = 1;i<=MX-4;i++)
        p2[i] = (p2[i-1]*2)%mod;
    while(cin>>n)
    {
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        ll ans = 0LL;
        ll s1 = 0LL;
        for(int i = 0;i<n;i++)
        {
            ans = (ans%mod + (1LL*(a[i]%mod)*1LL*(p2[i]-1))%mod)%mod;
        }
        for(int i = 0;i<n;i++)
        {
            s1 = (s1%mod + (1LL*(a[i]%mod)*1LL*(p2[n-i-1]-1))%mod)%mod;
        }
        cout << (ans + mod - s1)%mod << "\n";
    }
    return 0;
}
