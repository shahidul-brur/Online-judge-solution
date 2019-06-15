//Accepted

#include<stdio.h>
#include <string.h>
#define N 1000000
#define P 79000
int prime[N+2], digitprime[N+2];
int dgSum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main()
{
    freopen("10533.txt", "r", stdin);
    int t,i,j,L,R,s,cnt;
    memset(prime, 0, sizeof(prime));//let all are prime initially by mean 0
    prime[0]=1; // 1 mean not prime
    prime[1]=1;
    for(i=4;i<=N;i+=2)
        prime[i]=1;
    for(i=3;i<=N/i;i+=2)
    {
        if(prime[i]==0) // if prime
        {
            for(j=i*2;j<=N;j+=i)
                prime[j]=1;
        }
    }
    cnt=0;
    for(i=2;i<=N;i++)
    {
       if(prime[i]==0)
       {
           s=dgSum(i);
           if(prime[s]==0)
               cnt++;
       }
       digitprime[i]=cnt;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&L,&R);
        printf("%d\n",digitprime[R]-digitprime[L-1]);
    }
    return 0;
}
