#include<stdio.h>
unsigned long long int LC(unsigned long long int a,unsigned  long long int b)
{

    unsigned long long int gcd,i,lc,rem,min;
    if(a<b)
        min=a;
    else
        min=b;
    for(i=min;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
            break;
        }
    }
    lc=(a*b)/gcd;
    return lc;
}
int main()
{
    freopen("1024.txt", "r", stdin);
    unsigned long long num[1002], t, total, i, j, lcm;
    scanf("%llu", &t);
    for(i=1;i<=t;i++)
    {
        scanf("%llu",&total);
        for(j=0;j<total;j++)
            scanf("%llu",&num[j]);

        lcm=num[0];
        for(j=1;j<total;j++)
        {
           lcm=LC(lcm,num[j]);
        }
        printf("Case %llu: %llu\n",i,lcm);
    }
    return 0;
}
