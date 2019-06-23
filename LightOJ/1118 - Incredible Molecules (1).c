#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    freopen("1118.txt", "r", stdin);
    int c,t;
    double x1,y1,r1,x2,y2,r2,d,ans,tri1,tri2,sector1,sector2,segment1,segment2,angle1,angle2;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        angle1=2*acos((d/2)/r1);
        angle2=2*acos((d/2)/r2);
        tri1=0.5*r1*r1*sin(angle1);
        tri2=0.5*r2*r2*sin(angle2);
        sector1=0.5*angle1*r1*r1;
        sector2=0.5*angle2*r2*r2;
        segment1=sector1-tri1;
        segment2=sector2-tri2;
        ans=segment1+segment2;
        printf("Case %d: %lf\n",c,ans);
    }
    return 0;
}
