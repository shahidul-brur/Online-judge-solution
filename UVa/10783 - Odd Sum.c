//Accepted

#include<stdio.h>
int main()
{
    int t, i,j, a,b,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&a);
        scanf("%d",&b);
        for(j=a;j<=b;j++)
        {
            if(j%2==1) sum+=j;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
