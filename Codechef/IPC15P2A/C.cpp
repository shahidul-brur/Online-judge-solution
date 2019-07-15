#include<bits/stdc++.h>
using namespace std;
long long now[8], pre[8], mod = 1000000007, n, m, k;
int main()
{
    cin>>n>>k>>m;
    for(long long i=1;i<=k;i++)
        pre[i] = m%mod;
    now[1] = m%mod;
    for(long long i=2;i<=n;i++)
    {
        for(long long j=2;j<=k;j++)
            now[j] =  ((pre[j]%mod + now[j-1]%mod)%mod + pre[j-1]%mod)%mod;
        for(long long j=2;j<=k;j++)
            pre[j] = now[j];
    }
    cout << now[k]%mod << "\n";
    return 0;
}
