//Accepted
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //freopen("11760.txt", "r", stdin);
    int R, C, r, c, n, ar, ac, cas=1, i, j, wayL, wayR, wayU, wayD, way, way1, way2;
    int row[10003];
    int col[10003];

    while(scanf("%d %d %d",&R,&C,&n)!=EOF)
    {
        if(R==0 && C==0 && n==0)
            break;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&r,&c);
            row[r]=1;
            col[c]=1;
        }
        scanf("%d%d",&ar, &ac);

        way=0;
        wayL=0;
        wayR=0;
        wayU=0;
        wayD=0;

        if(row[ar]==1 || col[ac]==1)
        {
            if(row[ar]==1)
            {
                way=1;
                wayL=1;
                wayR=1;
            }

            if(ar==0)
                wayU=1;
            if(ar>0)
                if(row[ar-1]==1)
                   wayU=1;

            if(ar==R-1)
                wayD=1;
            if(ar<R-1)
                if(row[ar+1]==1)
                   wayD=1;

            if(col[ac]==1)
            {
                wayU=1;
                wayD=1;
                way=1;
            }

            if(ac==0)
                wayL=1;
            if(ac>0)
                if(col[ac-1]==1)
                   wayL=1;

            if(ac==C-1)
                wayR=1;
            if(ac<C-1)
                if(col[ac+1]==1)
                   wayR=1;
        }
        if(way==1 && wayL==1 && wayR==1 && wayU==1 && wayD==1)
            printf("Case %d: Party time! Let's find a restaurant!\n", cas);
        else
            printf("Case %d: Escaped again! More 2D grid problems!\n", cas);
        cas++;
    }
    return 0;
}
