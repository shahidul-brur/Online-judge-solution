//Accepted

#include <stdio.h>
#include <string.h>
#define N 20000000
#define P 1270610
int prime[N+2], twinPrime1[P], twinPrime2[P], primeList[P];
int main()
{
    int p=1, i, j,cnt=0, n;
    memset(prime, 0, sizeof(prime));
    prime[0]=1;
    prime[1]=1;
    for(i=4;i<=N;i+=2)
        prime[i]=1;
    for(i=3;i<=N/i;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*2;j<=N;j+=i)
                prime[j]=1;
        }
    }
    for(i=2;i<=N;i++)
        if(prime[i]==0)
            primeList[cnt++]=i;
    for(i=0;i<cnt;i++)
    {
        if(primeList[i+1] - primeList[i] == 2)
        {
            twinPrime1[p]=primeList[i];
            twinPrime2[p]=primeList[i+1];
            p++;
        }
    }
    while(scanf("%d", &n)!=EOF)
    {
        printf("(%d, %d)\n", twinPrime1[n], twinPrime2[n]);
    }
    return 0;
}
