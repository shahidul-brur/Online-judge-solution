//Accepted

#include <stdio.h>
#include <math.h>
#define PI acos(-1)
int main()
{
    freopen("10221.txt", "r", stdin);
    double s, a, r;
    char unit[6];
    r=6440.0;
    while(scanf("%lf %lf %s", &s, &a, unit)==3)
    {
        if(unit[0]=='m')
            a=(double)a/60.0;
        if(a>180.0)
            a=360.0-a;
        a=(double)((PI*a)/180.0);
        printf("%.6lf %.6lf\n",(r+s)*a, 2.0*(r+s)*sin(a/2.0));
    }
    return 0;
}
