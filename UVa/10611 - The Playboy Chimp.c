//Accepted
#include<stdio.h>
int main()
{
    //freopen("10611.txt", "r", stdin);
    int n,g[50005],q,h,i,j,s,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&g[i]);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&h);
        s=0;
        for(i=1;i<=n;i++)
        {
            if(g[i]<h)
                s=g[i];
            else break;
        }
        t=0;
        for(i=n;i>=1;i--)
        {
            if(g[i]>h)
                t=g[i];
            else break;
        }
        if(s==0)
            printf("X ");
        else printf("%d ",s);
        if(t==0)
            printf("X\n");
        else printf("%d\n",t);
    }
    return 0;
}
