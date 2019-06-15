//Accepted

#include<stdio.h>
int main()
{
    //freopen("10079.txt", "r", stdin);
    long long int n,i,ans;
    while(scanf("%lld",&n) && n>=0)
    {
        ans=1;
        for(i=0;i<=n;i++)
            ans=ans+i;
        printf("%lld\n",ans);
    }
    return 0;
}
