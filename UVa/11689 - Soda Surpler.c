//Accepted

#include<stdio.h>
int main()
{
    freopen("11689.txt", "r", stdin);
    long long int a,b,c,botl,t,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        botl=a+b;
        ans=0;
        while(botl>=c)
        {
            ans+=botl/c;
            botl=botl/c+(botl%c);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
