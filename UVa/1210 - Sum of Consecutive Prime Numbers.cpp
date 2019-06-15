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
    freopen("1210.txt", "r", stdin);
    long i,k=1,j,prime[1235],n,sum,Count;
    for(i=2;i<=10000;i++)
       if(isPrime(i)==1)
            prime[k++]=i;
        k--;
    while(scanf("%ld",&n)&&n!=0)
    {
        Count=0;
         for(i=1;i<=k;i++)
         {
             if(prime[i]>n)
                break;
            sum=0;
            for(j=i;j<=k;j++)
            {
                sum+=prime[j];
                if(sum==n)
                {
                    Count++;
                    break;
                }
            }

         }

        printf("%ld\n",Count);
    }
    return 0;
}
