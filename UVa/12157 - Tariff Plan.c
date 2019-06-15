#include<stdio.h>
int main()
{
    freopen("12157.txt", "r", stdin);
    int t,n,i,j,k,du,juice,mile;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        juice=mile=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&du);
            juice+=(du/60+1)*15;
            mile+=(du/30+1)*10;
        }
        if(juice<mile)
            printf("Case %d: Juice %d\n",i,juice);
        else if(mile<juice)
            printf("Case %d: Mile %d\n",i,mile);
        else if(mile==juice)
            printf("Case %d: Mile Juice %d\n",i,mile);
    }
    return 0;
}
