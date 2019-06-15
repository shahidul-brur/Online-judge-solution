//Accepted

#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    double a,b,c;
    double as,av,ar,at,total,s,r,R;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        s=(a+b+c)/2;
        at=sqrt(s*(s-a)*(s-b)*(s-c));
        R=(a*b*c)/(4*at);
        total=PI*R*R;
        as=total-at;
        r=(2*at)/(a+b+c);
        ar=PI*r*r;
        av=at-ar;
        printf("%.4lf %.4lf %.4lf\n",as,av,ar);
    }
    return 0;
}
