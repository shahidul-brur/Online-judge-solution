//Accepted

#include<stdio.h>
int main()
{
    freopen("438.txt", "r", stdin);
    double x1,y1,x2,y2,x3,y3,g,f,c,r,det,p;
    while(scanf("%lf %lf  %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        det=4*((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2));
        g=2*((x2*x2+y2*y2-x1*x1-y1*y1)*(y1-y3)-(x3*x3+y3*y3-x1*x1-y1*y1)*(y1-y2))/det;
        f=2*((x1-x2)*(x3*x3+y3*y3-x1*x1-y1*y1)-(x1-x3)*(x2*x2+y2*y2-x1*x1-y1*y1))/det;
        c=-(x1*x1)-(y1*y1)-2*g*x1-2*f*y1;
        r=sqrt(g*g+f*f-c);
        p=2*r*3.141592653589793;
        printf("%.2lf\n",p);
    }
    return 0;
}
