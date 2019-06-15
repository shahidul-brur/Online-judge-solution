//Accepted

#include<stdio.h>
long long modSum(long n)
{
    if(n==0)
        return 0;
    long long s1=0,s2=0,m;
    while(n>0)
    {
        m=n%10;
        n=n/10;
        s1+=m*(m+1)/2;
        s2+=(double)n*45;
    }
    return s1+s2;
}
int main()
{
    freopen("10994.txt", "r", stdin);
    long long int p,q,sum;
    while(scanf("%lld %lld",&p,&q)==2)
    {
        if(p<0 && q<0)
            break;
        if(p>0)
            sum=modSum(q)-modSum(p-1);
        else sum=modSum(q);
        printf("%lld\n",sum);
    }
    return 0;
}
