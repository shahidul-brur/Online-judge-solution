//Accepted

#include<stdio.h>
#include<math.h>
long isPrime(long long a)
{
    long long l;
    for(l=2;l<=a/l;l++)
      if(a%l==0)
        return 0;
    return 1;
}
long long sq(long long n)
{
    return n*n;
}
long long bigmod(long long b, long long p, long long m)
{
    if(p==0)
        return 1;
    if(p%2==0)
        return sq(bigmod(b,p/2,m))%m;
    return ((b%m)*bigmod(b,p-1,m))%m;
}
int main()
{
    freopen("11287.txt", "r", stdin);
    long long int a,p,pr,s;
    while(scanf("%lld %lld",&p,&a)!=EOF)
    {
        if(p==0 && a==0)
            break;

        if(isPrime(p)==0 && bigmod(a,p,p)==a)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

