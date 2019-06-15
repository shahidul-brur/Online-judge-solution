#include<stdio.h>
int main()
{
    //freopen("378.txt", "r", stdin);
    int t,i,j;
    float x1,y1,x2,y2,x3,y3,x4,y4,a1,b1,c1,a2,b2,c2,det,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        a1=y1-y2;
        b1=x2-x1;
        c1=a1*x1+b1*y1;
        a2=y2-y3;
        b2=x2-x3;
        c2=a2*x2+b2*y2;
        det=a1*b2-a2*b1;
        x=(c1*b2-c2*b1)/det;
        y=(a1*c2-a2*c1)/det;
        printf("%f %f %f %f %f %f %f %f\n",a1,b1,c1,a2,b2,c2,x,y);
    }
    return 0;
}
