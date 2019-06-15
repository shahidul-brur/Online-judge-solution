//Accepted

#include<stdio.h>
int isPrime(long num)
{
    long i;
    for(i=3;i<=num/i;i+=2)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    freopen("543.txt", "r", stdin);
    long i,n,a,b,c,d;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n<8)
        {
            printf("Impossible.\n");
            continue;
        }
        a=2;
        b=2+n%2;
        n-=a+b;
        if(n==4)
            c=2;
        else
            for(c=3;;c+=2)
                if(isPrime(c))
                    if(isPrime(n-c))
                        break;
        printf("%ld %ld %ld %ld\n",a,b,c,n-c);
    }
    return 0;
}
