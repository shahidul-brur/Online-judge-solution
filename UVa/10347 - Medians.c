//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    double d,e,f,area;
    while(scanf("%lf %lf %lf",&d,&e,&f)!=EOF)
    {
        if(d+e<=f || e+f<=d || f+d<=e)
            printf("-1.000\n");
        else
        {
            area=sqrt(2*(d*d*e*e+e*e*f*f+f*f*d*d)-(d*d*d*d+e*e*e*e+f*f*f*f))/3.0;
            printf("%.3lf\n",area);
        }
    }
    return 0;
}
