//Accepted

#include<stdio.h>
int main()
{
    //freopen("661.txt", "r", stdin);
    int n,o,c,p[30],i,j,op,st[30],total,Max,cas=1;
    while(scanf("%d %d %d",&n,&o,&c)==3)
    {
        if(n==0 && o==0 && c==0)
            break;

        for(i=1;i<=n;i++)
            st[i]=0;

        for(i=1;i<=n;i++)
            scanf("%d",&p[i]);

        Max=total=0;

        for(i=1;i<=o;i++)
        {
            scanf("%d",&op);
            st[op]++;
            if(st[op]%2==1)
                total+=p[op];
            else
                total-=p[op];
            if(total>Max)
                Max=total;
        }
        if(Max>c)
            printf("Sequence %d\nFuse was blown.\n\n",cas);
        else
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",cas,Max);
       cas++;
    }
    return 0;
}
