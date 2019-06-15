#include <stdio.h>
#include <math.h>
#define eps 1e-6
int main()
{
    freopen("573.txt", "r", stdin);
    double h,u,d,f,p;
    int fail,day,success;
    while(scanf("%lf",&h)!=EOF)
    {
        if(h==0)
            break;
        scanf("%lf %lf %lf",&u,&d,&f);
        f=f/100.0;
        f=floorf(f*100.0)/100.0;
        success=fail=0;
        day=1;
        p=0.0;
        while(day>0)
        {
            printf("%.3lf", p);
            p=p+u;
            p=floorf(p*10.0)/10.0;
            printf(" + %.3lf = %.3lf ", u, p);
            if(p>h+eps)
            {
                success=1;
                break;
            }
            p=p-d;
            p=floorf(p*10.0)/10.0;
            printf("- %.3lf = %.3lf\n", d, p);
            if(p<eps)
            {
                fail=1;
                break;
            }
            u=u-u*f;
            u=floorf(u*10.0)/10.0;
            day++;
        }
        if(p>h+eps)
            success=1;
        if(fail==1)
            printf("failure on day %d\n",day);
        else if(success==1)
            printf("success on day %d\n",day);
    }
    return 0;
}
