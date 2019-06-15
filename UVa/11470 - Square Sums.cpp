//Accepted

#include<stdio.h>
int main()
{
    freopen("11470.txt", "r", stdin);
    int n,i,j,k,c=1,grid[15][15],L,sum;
    while(scanf("%d",&n)&&n!=0)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }
        printf("Case %d:",c);
        for(i=1;i<=n/2;i++)
        {
            sum=0;
            for(j=i,k=i;k<=n-i+1;k++)
                sum+=grid[j][k];
            for(j=n-i+1,k=i;k<=n-i+1;k++)
                sum+=grid[j][k];
            for(j=i+1,k=i;j<=n-i;j++)
                sum+=grid[j][k];
            for(j=i+1,k=n-i+1;j<=n-i;j++)
                sum+=grid[j][k];
            printf(" %d",sum);
        }
        if(n%2==1)
            printf(" %d",grid[n/2+1][n/2+1]);
        printf("\n");
        c++;
    }
    return 0;
}
