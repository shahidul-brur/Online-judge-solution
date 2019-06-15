//Accepted

#include<stdio.h>
int main()
{
    int t, n, pl[13],i,j,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&pl[j]);
        c=(n+1)/2;
        printf("Case %d: %d\n",i,pl[c]);
    }
    return 0;
}
