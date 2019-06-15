//Accepted

#include<stdio.h>
struct figure
{
    double xL,xR,yU,yL;
};
int main()
{
    //freopen("476.txt","r",stdin);
    double x,y;
    char ch[5];
    int i,j,f=1,p,con;
    struct figure fig[15];
    while(scanf("%s",&ch)!=EOF)
    {
        if(ch[0]=='*')
            break;
        scanf("%lf %lf %lf %lf",&fig[f].xL,&fig[f].yU,&fig[f].xR,&fig[f].yL);
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
            if((x>fig[i].xL && x<fig[i].xR) && (y>fig[i].yL && y<fig[i].yU))
            {
                printf("Point %d is contained in figure %d\n",p,i);
                con=1;
            }
        }
        if(con==0)
            printf("Point %d is not contained in any figure\n",p);
        p++;
    }
    return 0;
}
