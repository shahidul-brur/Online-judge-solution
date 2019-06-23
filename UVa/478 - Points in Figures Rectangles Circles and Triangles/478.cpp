//Accepted

#include<stdio.h>
#include<math.h>
#define exp 1e-6
struct figure
{
    char figType;
    double xL,xR,yU,yL,Cx,Cy,r, x1,y1,x2,y2,x3,y3,area;
}fig[15];
int main()
{
    freopen("478.txt","r",stdin);
    double x,y,dis,area1,area2,area3,s,a,b,c;
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
        else if(ch[0]=='t')
        {
            scanf("%lf %lf %lf %lf %lf %lf", &fig[f].x1, &fig[f].y1, &fig[f].x2, &fig[f].y2, &fig[f].x3, &fig[f].y3);
            a=sqrt((fig[f].x2-fig[f].x1)*(fig[f].x2-fig[f].x1)+(fig[f].y2-fig[f].y1)*(fig[f].y2-fig[f].y1));
            b=sqrt((fig[f].x3-fig[f].x1)*(fig[f].x3-fig[f].x1)+(fig[f].y3-fig[f].y1)*(fig[f].y3-fig[f].y1));
            c=sqrt((fig[f].x2-fig[f].x3)*(fig[f].x2-fig[f].x3)+(fig[f].y2-fig[f].y3)*(fig[f].y2-fig[f].y3));
            s=(double)(a+b+c)/2.0;
            fig[f].area=(double)sqrt(s*(s-a)*(s-b)*(s-c));
        }

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
            else if(fig[i].figType=='t')
            {
                a=(double)sqrt((fig[i].x2-fig[i].x1)*(fig[i].x2-fig[i].x1)+(fig[i].y2-fig[i].y1)*(fig[i].y2-fig[i].y1));
                b=(double)sqrt((x-fig[i].x1)*(x-fig[i].x1)+(y-fig[i].y1)*(y-fig[i].y1));
                c=(double)sqrt((fig[i].x2-x)*(fig[i].x2-x)+(fig[i].y2-y)*(fig[i].y2-y));
                s=(double)(a+b+c)/2.0;
                area1=(double)sqrt(s*(s-a)*(s-b)*(s-c));

                a=(double)sqrt((fig[i].x2-fig[i].x3)*(fig[i].x2-fig[i].x3)+(fig[i].y2-fig[i].y3)*(fig[i].y2-fig[i].y3));
                b=(double)sqrt((x-fig[i].x2)*(x-fig[i].x2)+(y-fig[i].y2)*(y-fig[i].y2));
                c=(double)sqrt((x-fig[i].x3)*(x-fig[i].x3)+(y-fig[i].y3)*(y-fig[i].y3));
                s=(double)(a+b+c)/2.0;
                area2=(double)sqrt(s*(s-a)*(s-b)*(s-c));

                a=(double)sqrt((fig[i].x1-fig[i].x3)*(fig[i].x1-fig[i].x3)+(fig[i].y1-fig[i].y3)*(fig[i].y1-fig[i].y3));
                b=(double)sqrt((x-fig[i].x1)*(x-fig[i].x1)+(y-fig[i].y1)*(y-fig[i].y1));
                c=(double)sqrt((x-fig[i].x3)*(x-fig[i].x3)+(y-fig[i].y3)*(y-fig[i].y3));
                s=(double)(a+b+c)/2.0;
                area3=(double)sqrt(s*(s-a)*(s-b)*(s-c));

                if((area1+area2+area3)-fig[i].area<=exp)
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
