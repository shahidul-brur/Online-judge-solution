//Accepted

#include<stdio.h>
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
    freopen("406.txt", "r", stdin);
    int n,c,i,j,prime[1010],k=1,count,L,R;
    prime[1]=1;
    for(i=2;i<=1000;i++)
    {
        if(isPrime(i)==1)
        {
            k++;
            prime[k]=i;
        }
    }
    while(scanf("%d %d",&n,&c)!=EOF)
    {
        if(n==0 && c==0)
            break;
        for(i=1;i<=k && prime[i]<=n;i++);
        count=i-1;
        if(count%2==0)
        {
            L=count/2-c+1;
            R=count/2+c;
        }
        else
        {
            L=count/2-c+2;
            R=count/2+c;
        }
        if(L<1)
            L=1;
        if(R>count)
            R=count;
        printf("%d %d:",n,c);
        for(i=L;i<=R;i++)
            printf(" %d",prime[i]);
        printf("\n\n");
    }
    return 0;
}
