//Accepted

#include<stdio.h>
#include<math.h>
struct figure
{
    char figType;
    double xL,xR,yU,yL,Cx,Cy,r;
}fig[15];
int main()
{
    freopen("477.txt","r",stdin);
    double x,y,dis;
    char ch[5];
    int i,j,f=1,p,con;
    while(scanf("%s",&ch)!=EOF)
    {
        if(ch[0]=='*')
            break;
        if(ch[0]=='r')
            scanf("%lf %lf %lf %lf",&fig[f].xL,&fig[f].yU,&fig[f].xR,&fig[f].yL);
        else if(ch[0]=='c')
            scanf("%lf %lf %lf", &fig[f].Cx, &fig[f].Cy, &fig[f].r);
        fig[f].figType=ch[0];
        f++;
    }
    p=1;
    while(scanf("%lf %lf",&x,&y)==2)
    {
        if(x==9999.9 && y==9999.9)
            break;
        con=0;
        for(i=1;i<f;i++)
        {
            if(fig[i].figType=='r')
            {
                if((x>fig[i].xL && x<fig[i].xR) && (y>fig[i].yL && y<fig[i].yU))
                {
                    printf("Point %d is contained in figure %d\n",p,i);
                    con=1;
                }
            }
            else if(fig[i].figType=='c')
            {
                dis=sqrt((x-fig[i].Cx)*(x-fig[i].Cx)+(y-fig[i].Cy)*(y-fig[i].Cy));
                if(dis<fig[i].r)
                {
                    printf("Point %d is contained in figure %d\n",p,i);
                    con=1;
                }
            }
        }
        if(con==0)
            printf("Point %d is not contained in any figure\n",p);
        p++;
    }
    return 0;
}
