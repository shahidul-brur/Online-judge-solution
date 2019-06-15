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
    //freopen("543.txt", "r", stdin);
    long i,k=1,j,prime[78600],n,op,from,to,m,count;
    for(i=2;i<=32768;i++)
       if(isPrime(i)==1)
            prime[k++]=i;
        k--;
    while(scanf("%ld",&n)&&n!=0)
    {
        count=0;
         for(i=1;i<=k;i++)
         {
             if(prime[i]>=n)
                break;
             op=n-prime[i];
             from=i;
             to=k;
             while(from<to)
             {
                 m=(from+to)/2;
                 if(op>prime[m])
                    from=m+1;
                 else if(op==prime[m])
                 {
                     from=m;
                     break;
                 }
                 else if(op<prime[m])
                    to=m;

             }
             if(prime[from]==op)
                count++;
        }
        printf("%ld\n",count);
    }
    return 0;
}
