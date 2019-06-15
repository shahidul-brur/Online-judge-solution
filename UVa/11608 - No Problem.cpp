//Accepted
#include<stdio.h>
int main()
{
    //freopen("11608.txt", "r", stdin);
    int pre,req,p[15],has,i,j,c=1;
    while(scanf("%d",&pre)!=EOF)
    {
        if(pre<0)
            break;
        for(i=1;i<=12;i++)
            scanf("%d",&p[i]);
        printf("Case %d:\n",c);
        has=pre;
        for(i=1;i<=12;i++)
        {
            scanf("%d",&req);
            if(has>=req)
            {
                printf("No problem! :D\n");
                has-=req;
            }
            else
                printf("No problem. :(\n");
            has+=p[i];
         }
        c++;
    }
    return 0;
}
