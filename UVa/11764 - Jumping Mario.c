//Accepted

#include<stdio.h>
int main()
{
    //freopen("11764.txt", "r", stdin);
    int t,n,i,j,wall[60],low,high;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        low=high=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&wall[j]);
        for(j=1;j<n;j++)
        {
            if(wall[j]>wall[j+1])
                low++;
            else if(wall[j]<wall[j+1])
                    high++;
        }
        printf("Case %d: %d %d\n",i,high,low);
    }
}
