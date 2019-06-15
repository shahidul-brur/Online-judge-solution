#include<stdio.h>
int main()
{
    freopen("10887.txt", "r", stdin);
    int m,n,i,j,t,k;
    char str[15];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&m,&n);
        for(j=1;j<=m;j++)
            scanf("%s",&str);
        for(j=1;j<=n;j++)
            scanf("%s",&str);
        printf("Case %d: %d\n",i,m*n);
    }
    return 0;
}
