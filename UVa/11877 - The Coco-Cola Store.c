//Accepted
#include<stdio.h>
int main()
{
    long long int a,ans;
    while(scanf("%lld",&a) && a!=0)
    {
        ans=0;
        while(a>=3)
        {
            ans+=a/3;
            a=a/3+(a%3);
        }
        if(a==2)
            ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
