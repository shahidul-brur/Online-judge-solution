#include<stdio.h>
#include<string.h>
#include<math.h>
long sq(int n)
{
    return n*n;
}
long bigmod(long b, long p, long m)
{
    if(p==0)
        return 1;
    if(p%2==0)
        return sq(bigmod(b,p/2,m))%m;
    return ((b%m)*bigmod(b,p-1,m))%m;
}
int main()
{
    freopen("10006.txt", "r", stdin);
    int i,n,c,j,prime[65000];
    memset(prime, 0, sizeof(prime));
    prime[0]=prime[1]=1;
    for(i=4;i<=65000;i+=2)
        prime[i]=1;
    for(i=3;i<=255;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=65000;j+=i)
                prime[j]=1;
        }
    }
    while(scanf("%d",&n)&&n!=0)
    {
        if(prime[n]==0)
            printf("%d is normal.\n",n);
        else
        {
            c=0;
            for(i=2;i<n;i++)
            {
                if(bigmod(i,n,n)==i)
                {
                    c=1;
                    break;
                }
            }
            if(c==1)
                printf("The number %d is a Carmichael number.\n",n);
            else
                printf("%d is normal.\n",n);
        }
    }
    return 0;
}
