/*Accepted*/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("10041.txt", "r", stdin);
    int t, r, num[515],i,j,k,temp;
    long long int sum=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&r);
        for(j=0;j<r;j++)
        {
            scanf("%d",&num[j]);
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<=(r-2);k++)
            {
                if(num[k]>num[k+1])
                {
                    temp=num[k];
                    num[k]=num[k+1];
                    num[k+1]=temp;
                }
            }
        }
        for(j=0;j<r;j++)
        {
            sum+=abs(num[r/2]-num[j]);
        }
        printf("%lld\n",sum);
        sum=0;
    }
    return 0;
}
