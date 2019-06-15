#include<stdio.h>
int main()
{
    freopen("10213.txt", "r", stdin);
    long long t,n,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=n*(n-1)/2+1;
        printf("%lld\n",ans);
    }
    return 0;
}
