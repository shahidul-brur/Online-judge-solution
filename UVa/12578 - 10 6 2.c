//Accepted

#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    int t;
    double l,w,r,total,red,green;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&l);
        w=(l*6)/10;
        r=(l*2)/10;
        total=l*w;
        red=PI*r*r;
        green=total-red;
        printf("%.2lf %.2lf\n",red,green);
    }
    return 0;
}
