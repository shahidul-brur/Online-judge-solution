//Accepted
#include <stdio.h>
int isPrime(long long int num)
{
    if(num<2)
        return 0;
    long i;
    for(i=2;i<num/i;i++)
        if(num%i==0)
            return i;
    return 1;
}
int isPallin(long long int num)
{
    if(num<10)
        return 1;
    long long int rev=0, j, tmp;
    tmp=num;
    while(tmp>0)
    {
        rev=rev*10+tmp%10;
        tmp=tmp/10;
    }
    if(rev==num)
        return 1;
    else
        return 0;
}
int main()
{
    long long int n, d;
    while(scanf("%lld",&n)!=EOF)
    {
        d=2*n;
        printf("%lld\n",d);
        if(isPrime(n)==1 && isPallin(n)==1)
            break;
    }
    return 0;
}
