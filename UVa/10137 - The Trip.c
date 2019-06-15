//Accepted
#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("10137.txt", "r", stdin);
    int n,i;
    double avg,exSum1,exSum2,sum,indv[1010];
    while(scanf("%d",&n) && n!=0)
    {
        sum=exSum1=exSum2=0.0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&indv[i]);
            sum+=indv[i];
        }
        avg=sum/n;
        for(i=1;i<=n;i++)
        {
            if(indv[i]<avg)
                exSum1+=(double)(long)((avg-indv[i])*100.0)/100.0;
        }
        for(i=1;i<=n;i++)
        {
            if(indv[i]>avg)
                exSum2+=(double)(long)((indv[i]-avg)*100.0)/100.0;
        }
        if(exSum1>exSum2)
            printf("$%.2lf\n",exSum1);
        else
            printf("$%.2lf\n",exSum2);
    }
    return 0;
}
