//Accepted

#include<stdio.h>
int isPrime(long num)
{
    long i;
    for(i=2;i<=num/i;i++)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    freopen("10699.txt", "r", stdin);
    long i,k=1,j,prime[78600],n,r,count,op;
    for(i=2;i<=1000000;i++)
       if(isPrime(i)==1)
            prime[k++]=i;

    while(scanf("%ld",&n)&&n!=0)
    {

            count=0;
            for(i=1;i<k;i++)
            {
                if(prime[i]>n)
                    break;
                if(n%prime[i]==0)
                    count++;
             }
            printf("%ld : %ld\n",n,count);


    }
    return 0;
}
