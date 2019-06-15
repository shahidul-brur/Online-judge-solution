//Accepted
#include<stdio.h>
int main()
{
    freopen("460.txt", "r", stdin);
    int c=1,t,x3,y3,x4,y4,x5,y5,x6,y6,over,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--)
    {
        over=1;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        if((x3>=x2||x4<=x1) || (y3>=y2||y4<=y1))
            over=0;
        if(over==1)
        {
            if(x3<x1)
                x5=x1;
            else
                x5=x3;

            if(y3<y1)
                y5=y1;
            else
                y5=y3;

            if(x4>x2)
                x6=x2;
            else
                x6=x4;

            if(y4>y2)
                y6=y2;
            else
                y6=y4;

        }
        if(c>1)
            printf("\n");
       if(over==0)
            printf("No Overlap\n");
       else
            printf("%d %d %d %d\n",x5,y5,x6,y6);
        c++;
    }
    return 0;
}
