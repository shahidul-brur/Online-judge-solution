#include<stdio.h>
int main()
{
    long long int a, b,ans;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a>b) ans=a-b;
        else ans=b-a;
        printf("%lld\n",ans);
    }
    return 0;
}
