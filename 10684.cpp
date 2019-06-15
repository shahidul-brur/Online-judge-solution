//Accepted

#include <stdio.h>
int main()
{
    freopen("10684.txt", "r", stdin);
    int n, i, tk, sum, maxi;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        sum=0;
        maxi=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&tk);
            if(sum+tk>0)
                sum+=tk;
            else
                sum=0;

            if(sum>maxi)
                maxi=sum;
        }
        if(maxi>0)
            printf("The maximum winning streak is %d.\n", maxi);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
