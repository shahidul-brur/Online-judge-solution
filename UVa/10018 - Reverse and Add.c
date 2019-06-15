#include<stdio.h>
long long int reverse(long long int num)
{
    long long int rev=0,rem;
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    return rev;
}
int main()
{
    long long int t,n,count,sum,j;
    scanf("%lld",&t);
    while(t--)
    {
        count=1;
        scanf("%lld",&n);
       sum=n+reverse(n);
       while(sum!=reverse(sum))
       {
           n=sum;
           sum=n+reverse(n);
           count++;
       }
       printf("%lld %lld\n",count,sum);
    }
    return 0;
}
