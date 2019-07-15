#include <bits/stdc++.h>
using namespace std;
long long m = 1000000007;
long long sq(long long n)
{
    return (((n)%m)*(n)%m)%m;
}
long long pw(long long a, long long p)
{
    if(p==0)
        return 1;
    if(a==0)
        return 0;
    if(a==1)
        return 1;
    if(p==1)
        return a%m;

    if(p%2==0)
        return sq(pw(a, p/2))%m;
    else return ((a %m)*pw(a, p-1)%m)%m;
}
int main()
{
    long long n, t, ans, p, i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 1;
        for(i=1, p=n;i<=n;i++, p--)
        {
            ans = (ans%m)*(pw(i, p)%m)%m;
        }
        cout << ans << "\n";
    }
    return 0;
}
