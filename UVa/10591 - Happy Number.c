//Accepted

#include<stdio.h>
int dSqSum(int num)
{
    int i,rem,n=0;
    while(num>0)
    {
        rem=num%10;
        n=n+rem*rem;
        num=num/10;
    }
    return n;
}
int main()
{
    freopen("10591.txt", "r", stdin);
    int n,c,t,N;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        N=n;
        n=dSqSum(n);
        while(n>9)
        {
            n=dSqSum(n);
        }
        if(n==1)
            printf("Case #%d: %d is a Happy number.\n",c,N);
        else
            printf("Case #%d: %d is an Unhappy number.\n",c,N);
    }
    return 0;
}
