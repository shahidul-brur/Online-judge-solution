#include <stdio.h>
#include <math.h>
#define eps 1e-6
#define EPS 5e-5
int main()
{
    freopen("453.txt", "r", stdin);
    freopen("453.out", "w", stdout);
    double a, b, c, d, c1, c2, X1, X2, Y1, Y2, e, f, p, k, r, s;
    while(scanf("%lf %lf %lf", &a, &b, &r)!=EOF)
    {
        scanf("%lf %lf %lf", &c, &d, &s);

        e = c - a;
        f = d - b;
        p = sqrt(e*e + f*f);
        k = (p*p + r*r - s*s)/(2.0*p);

        if(fabs(a-c)<eps && fabs(b-d)<eps && fabs(r-s)<eps && r<eps)
        {
            printf("(%.3lf,%.3lf)\n", a,b);
            continue;
        }

        if(fabs(a-c)<eps && fabs(b-d)<eps && fabs(r-s)>eps)
        {
            printf("(%.3lf,%.3lf)\n", a,b);
            continue;
        }

        if(fabs(a-c)<eps && fabs(b-d)<eps && fabs(r-s)<eps)
        {
            printf("THE CIRCLES ARE THE SAME\n");
            continue;
        }

        if(p>(r+s)+eps || (p+s)+eps<r || (p+r)+eps<s)
        {
            printf("NO INTERSECTION\n");
            continue;
        }

        X1 = X2 = a + (e*k)/p;
        Y1 = Y2 = b + (f*k)/p;
        if(fabs(r*r - k*k)<eps);
        else
        {
            X1 -= (f/p)*sqrt(r*r - k*k);
            Y1 += (e/p)*sqrt(r*r - k*k);
            X2 += (f/p)*sqrt(r*r - k*k);
            Y2 -= (e/p)*sqrt(r*r - k*k);
        }
        if(X1<1e-4 && X1>-1e-4)
            X1=0.0;
        if(X2<1e-4 && X2>-1e-4)
            X2=0.0;
        if(Y1<1e-4 && Y1>-1e-4)
            Y1=0.0;
        if(Y2<1e-4 && Y2>-1e-4)
            Y2=0.0;

        if(X1+eps<X2)
        {
            printf("(%.3lf,%.3lf)", X1, Y1);
            if(fabs(X1-X2)<1e-8 && fabs(Y1-Y2)<1e-8);
            else
                printf("(%.3lf,%.3lf)", X2, Y2);
        }
        else
        {
            printf("(%.3lf,%.3lf)", X2, Y2);
            if(fabs(X1-X2)<1e-8 && fabs(Y1-Y2)<1e-8);
            else
                printf("(%.3lf,%.3lf)", X1, Y1);
        }
        printf("\n");
    }
    return 0;
}
