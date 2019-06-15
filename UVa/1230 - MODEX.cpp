#include<stdio.h>
#include<math.h>
long sq(int n)
{
    return n*n;
}
long bigmod(long b, long p, long m)
{
    if(p==0)
        return 1;
    if(p%2==0)
        return sq(bigmod(b,p/2,m))%m;
    return ((b%m)*bigmod(b,p-1,m))%m;
}
int main()
{
    long long int b,p,m,mod,t;
    scanf("%lld",&t);
    while(t-->0)
    {
        scanf("%lld %lld %lld",&b,&p,&m);
        mod=bigmod(b,p,m);
        printf("%lld\n",mod);
    }
    return 0;
}

