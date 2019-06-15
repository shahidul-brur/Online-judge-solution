#include<stdio.h>
int main()
{
    freopen("12650.txt", "r", stdin);
    int d[10009],n,r,i,m;
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        if(n!=r)
        {
            for(i=1;i<=n;i++)
                d[i]=0;
        }
        for(i=1;i<=r;i++)
        {
            scanf("%d",&m);
            d[m]=1;
        }
        if(n==r)
            printf("*\n");
        else
        {
            for(i=1;i<=n;i++)
            {
                if(d[i]==0)
                    printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}
