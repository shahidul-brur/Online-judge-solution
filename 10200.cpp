//Accepted

#include <stdio.h>
#include <string.h>
#define MAX 3125315
#define N 100010042
#define eps 1e-7
int setBit(int n, int position)
{
    n = (n | (1 << position));
    return n;
}
int checkBit(int n, int position)
{
    n=n&(1<<position);
    return n;
}
int prime[MAX];
int main()
{
    freopen("10200.txt", "r", stdin);
    int i,j,L,R,cnt,num;
    double ans;
    prime[0]=setBit(prime[0], 0);
    prime[0]=setBit(prime[0], 1);
    for(i=4;i<=N;i+=2)
        prime[i>>5]=setBit(prime[i>>5], i&31);
    for(i=3;i<=N/i;i+=2)
    {
        if(checkBit(prime[i>>5], i&31)==0) // if prime
        {
            for(j=i*2;j<=N;j+=i)
                prime[j>>5]=setBit(prime[j>>5], j&31);
        }
    }
    while(scanf("%d %d", &L, &R)!=EOF)
    {
        cnt=0;
        for(i=L;i<=R;i++)
        {
            num=i*i+i+41;
            if(checkBit(prime[num>>5], num&31)==0)
                cnt++;
        }
        ans=(cnt*100.0/(R-L+1));
        printf("%.2lf\n", ans+eps);
    }
    return 0;
}
