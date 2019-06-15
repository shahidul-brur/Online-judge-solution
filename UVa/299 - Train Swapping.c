//Accepted
#include<stdio.h>
int main()
{
    int t,n,tr[60],i,j,c,count,temp;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        count=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&tr[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(tr[j]>tr[j+1])
                {
                    temp=tr[j];
                    tr[j]=tr[j+1];
                    tr[j+1]=temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}
