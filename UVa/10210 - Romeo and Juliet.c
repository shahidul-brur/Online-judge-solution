#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    freopen("10210.txt", "r", stdin);
    double x1,y1,x2,y2,a1,a2,d,ans,va1,va2,sq;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&a1,&a2)!=EOF)
    {

        sq=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        d=sqrt(sq);
        va1=tan((PI*a1)/180);
        va2=tan((PI*a2)/180);
        ans=d/va1+d/va2;
        printf("%.3lf\n",ans);
    }
    return 0;
}
