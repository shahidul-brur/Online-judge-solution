#include<stdio.h>
int prime[1000002];
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
    //freopen("406.txt", "r", stdin);
    int n,U,c,i,j,k=0,count,L,R;
    for(i=2;i<=1000000;i++)
    {
        if(isPrime(i)==1)
        {
            k++;
            prime[k]=i;
        }
        if(k>=1000000)
            break;
    }
    printf("%d %d\n", i, k);
    /*for(i=1;i<=k;i++)
        printf("%d, ",prime[i]);
    while(scanf("%d %d",&L,&U)!=EOF)
    {

    }*/
    return 0;
}
