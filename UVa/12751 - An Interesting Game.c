//Accepted

#include<stdio.h>
int main()
{
    int t,n,k,x,i,j,sum,take,rem,c;
    scanf("%d", &t);
    for(c=1;c<=t;c++)
    {
        take=0;
        scanf("%d %d %d",&n,&k,&x);
        sum=n*(n+1)/2;
        for(i=1,j=x;i<=k;i++,j++)
            take+=j;
        rem=sum-take;
        printf("Case %d: %d\n",c,rem);
    }
    return 0;
}
