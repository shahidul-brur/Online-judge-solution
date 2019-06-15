//Accepted

#include<stdio.h>
int main()
{
    freopen("12798.txt", "r", stdin);
    int n,m,goal,i,j,v,p;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        p=0;
        for(i=1;i<=n;i++)
        {
            goal=0;
            for(j=1;j<=m;j++)
            {
                scanf("%d",&v);
                if(v>0)
                    goal++;
            }
            if(goal==m)
                p++;
        }
        printf("%d\n",p);
    }
    return 0;
}
