//Accepted
#include<stdio.h>
int main()
{
    freopen("11639.txt", "r", stdin);
    int cas=1,t,x3,y3,x4,y4,x5,y5,x6,y6,x1,y1,x2,y2,strong,weak,unsecure;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        if((x3>=x2||x4<=x1) || (y3>=y2||y4<=y1))
            strong=0;
        else
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
         strong=(x6-x5)*(y6-y5);
        }
        weak=((x2-x1)*(y2-y1)-strong)+((x4-x3)*(y4-y3)-strong);
        unsecure=10000-(strong+weak);
        printf("Night %d: %d %d %d\n", cas,strong,weak,unsecure);
        cas++;
    }
    return 0;
}
