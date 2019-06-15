#include<stdio.h>
#include<math.h>
int main()
{
    freopen("10310.txt", "r", stdin);
    int n,i,flag;
    double gx,gy,dx,dy,x[1010],y[1010],g,d;
    while(scanf("%d %lf %lf %lf %lf",&n,&gx,&gy,&dx,&dy)!=EOF)
    {
        flag=0;
        for(i=1;i<=n;i++)
            scanf("%lf %lf",&x[i],&y[i]);
        for(i=1;i<=n;i++)
        {
            g=sqrt((gx-x[i])*(gx-x[i])+(gy-y[i])*(gy-y[i]));
            d=0.5*sqrt((dx-x[i])*(dx-x[i])+(dy-y[i])*(dy-y[i]));
            if(d>=g)
            {
                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x[i],y[i]);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("The gopher cannot escape.\n");
    }
    return 0;
}
