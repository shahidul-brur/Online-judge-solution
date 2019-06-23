#include<stdio.h>
long long int LC(long long int a, long long int b)
{

    long long int gcd,i,lc,rem,min;
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
    long long num[10000], t, total, i, j, k, max,all,lcm;
    scanf("%lld", &t);
    for(i=1;i<=t;i++)
    {
        max=0;
        scanf("%lld",&total);
        for(j=0;j<total;j++)
        {
            scanf("%lld",&num[j]);
            if(num[j]>max)
                max=num[j];
        }
        all=1;
        for(k=0;k<total;k++)
        {
           if(max%num[k]!=0)
           {
               all=0;
               break;
           }
        }
        if(all==1)
            lcm=max;
        else
        {
            lcm=num[0];
            for(j=1;j<total;j++)
            {
               lcm=LC(lcm,num[j]);
            }
        }
        printf("Case %lld: %lld\n",i,lcm);
    }
    return 0;
}
