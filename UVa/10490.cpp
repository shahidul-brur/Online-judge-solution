//Accepted
#include <stdio.h>
#include <math.h>
int isPrime(long long num)
{
    if(num<2)
        return 0;
    long i;
    if(num==2)
        return 1;
    for(i=2;i<=num/i;i++)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    long long p, n, c1, c2, perfect;
    while(scanf("%lld",&p)==1)
    {
        if(p==0)
            break;
        n = pow(2, p) - 1;
        c1=isPrime(p);
        c2=isPrime(n);
        if(c1==1 && c2==1)
        {
            perfect=pow(2, p-1) * n;
            printf("Perfect: %lld!\n", perfect);
        }
        else if(c1==1 && c2==0)
            printf("Given number is prime. But, NO perfect number is available.\n");
        else if(c1==0 && c2==0)
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
