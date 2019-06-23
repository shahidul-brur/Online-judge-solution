//Accepted
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1002
int prime[N], sum[N];
int isPrime(int num)
{
    int i;
    for(i=2;i<=num/i;i++)
        if(num%i==0)
            return 0;
    return 1;
}
int main()
{
    freopen("11728.txt", "r", stdin);
    int n, add, i, j, cas=1;
    memset(sum, 0, sizeof(sum));
    memset(prime, 0, sizeof(prime)); //all are prime
    prime[0]=prime[1]=1;
    for(i=4;i<=N;i+=2)
        prime[i]=1; // i is not prime, even!
    for(i=3;i<=N/i;i+=2)
    {
        if(prime[i]==0) // if prime
        {
            for(j=i*2;j<=N;j+=i)
                prime[j]=1;
        }
    }
    sum[0]=0;
    sum[1]=1;
    for(i=2;i<N;i++)
    {
        if(prime[i]==1)
        {
            add=0;
            for(j=1;j<=i/j;j++)
            {
                if(i%j==0)
                {
                    if(j==i/j)
                        add+=j;
                    else
                        add+=j+i/j;
                }
                if(add>1000)
                    break;
            }
            if(add<=1000)
                sum[add]=i;
        }
    }
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        if(prime[n-1]==0)
            printf("Case %d: %d\n", cas, n-1);
        else if(sum[n]==0)
            printf("Case %d: -1\n", cas);
        else printf("Case %d: %d\n", cas, sum[n]);
        cas++;
    }
    return 0;
}
