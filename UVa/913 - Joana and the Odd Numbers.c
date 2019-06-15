//Accepted

#include<stdio.h>
int main()
{
    long long int n,i,sum,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i+=2)
        {
            sum+=i;
        }
        ans=1;
        for(i=1;i<=sum;i++)
            ans+=2;
        ans=3*ans-12;
        printf("%lld\n",ans);
    }
    return 0;
}
