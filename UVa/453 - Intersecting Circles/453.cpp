#include <stdio.h>
#include <math.h>
#define eps 1e-4
int main()
{
    freopen("453.txt", "r", stdin);
    freopen("453.out", "w", stdout);
    double x1, y1, x2, y2, r1, r2, a, b, c, d, c1, c2, X1, X2, Y1, Y2, dis, tmp;
    while(scanf("%lf %lf %lf", &x1, &y1, &r1)!=EOF)
    {
        scanf("%lf %lf %lf", &x2, &y2, &r2);

        if(fabs(x1-x2)<eps && fabs(y1-y2)<eps && fabs(r1-r2)<eps)
        {
            printf("THE CIRCLES ARE THE SAME\n");
            continue;
        }
        dis=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

        if((dis+eps)>(r1+r2) || (dis+r2)+eps<r1 || (dis+r1)+eps<r2)
        {
            printf("NO INTERSECTION\n");
            continue;
        }
        if(fabs(x1-x2)<eps && fabs(y1-y2)<eps)
        {
            printf("NO INTERSECTION\n");
            continue;
        }
        c1=x1*x1 + y1*y1 - r1*r1;
        c2=x2*x2 + y2*y2 - r2*r2;
        d=c1-c2;
        a=4.0*((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        b=8.0*(x1-x2)*(x1*(y1-y2) - y1*(x1-x2)) - 4.0*d*(y1-y2);
        c=d*d + 4.0*c1*(x1-x2)*(x1-x2) - 4*x1*d*(x1-x2);
        Y1=double((-b-(double)sqrt(b*b - 4.0*a*c))/(2.0*a));
        Y2=double((-b+(double)sqrt(b*b - 4.0*a*c))/(2.0*a));
        X1=double((d-2.0*(y1-y2)*Y1)/(2.0*(x1-x2)));
        X2=double((d-2.0*(y1-y2)*Y2)/(2.0*(x1-x2)));

        if(X1<eps && X1>-eps)
            X1=0.0;
        if(Y1<eps && Y1>-eps)
            Y1=0.0;
        if(X2<eps && X2>-eps)
            X2=0.0;
        if(Y2<eps && Y2>-eps)
            Y2=0.0;

        if(X1+eps<=X2)
        {
            printf("(%.3lf,%.3lf)", X1,Y1);
            if(fabs(X1-X2)<eps && fabs(Y1-Y2)<eps);
            else
                printf(" (%.3lf,%.3lf)", X2,Y2);
            printf("\n");
        }
        else
        {
            printf("(%.3lf,%.3lf)", X2,Y2);
            if(fabs(X1-X2)<eps && fabs(Y1-Y2)<eps);
            else
                printf(" (%.3lf,%.3lf)", X1,Y1);
            printf("\n");
        }
    }
    return 0;
}
