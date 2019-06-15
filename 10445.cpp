#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#define PI acos(-1.0)
#define Eps 1e-8
using namespace std;
typedef struct point
{
    int x;
    int y;
    double angle;
    double degAngle;
};

bool operator < (point A, point B)
{
    if(A.x<B.x)
        return true;
    else return (A.y<B.y);
}
int sqr(int a)
{
    return a*a;
}
double getAngle(point p)
{
    return atan2(p.y, p.x);
}
bool cmp(point A, point B)
{
    return A.angle<B.angle;
}
int main()
{
    freopen("10445.txt", "r", stdin);
    int n, i, lowestIndex;
    double mini, maxi;
    point lowestPoint, points[22];
    while(scanf("%d", &n)!=EOF)
    {
        if(n<3)
            break;

        scanf("%d %d", &points[0].x, &points[0].y);
        lowestPoint=points[0];
        lowestIndex=0;

        for(i=1;i<n;i++)
        {
            scanf("%d %d", &points[i].x, &points[i].y);
            if(points[i]<lowestPoint)
            {
                lowestPoint=points[i];
                lowestIndex=i;
            }
        }

        swap(points[lowestIndex], points[0]);

        mini=400.0;
        maxi=0.0;

        for(i=0;i<4;i++)
        {
            points[i].x-= lowestPoint.x;
            points[i].y -= lowestPoint.y;
            points[i].angle=getAngle(points[i]);
        }
        sort(points+1, points + n, cmp);
        double a, b, c, s, area;
        a=sqrt(sqr(points[n-1].x-points[0].x)+sqr(points[n-1].y-points[0].y));
        b=sqrt(sqr(points[1].x-points[0].x)+sqr(points[1].y-points[0].y));
        c=sqrt(sqr(points[1].x-points[n-1].x)+sqr(points[1].y-points[n-1].y));
        s=(a+b+c)/2.0;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        points[0].degAngle=asin((2*area)/(a*b));
        for(i=1;i<(n-1);i++)
        {
            a=sqrt(sqr(points[i-1].x-points[i].x)+sqr(points[i-1].y-points[i].y));
            b=sqrt(sqr(points[i+1].x-points[i].x)+sqr(points[i+1].y-points[i].y));
            c=sqrt(sqr(points[i+1].x-points[i-1].x)+sqr(points[i+1].y-points[i-1].y));
            s=(a+b+c)/2.0;
            area=sqrt(s*(s-a)*(s-b)*(s-c));
            points[i].degAngle=asin((2*area)/(a*b));
        }
        a=sqrt(sqr(points[n-1].x-points[0].x)+sqr(points[n-1].y-points[0].y));
        b=sqrt(sqr(points[n-1].x-points[n-2].x)+sqr(points[n+1].y-points[n-2].y));
        c=sqrt(sqr(points[0].x-points[n-2].x)+sqr(points[0].y-points[n-2].y));
        s=(a+b+c)/2.0;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        points[n-1].degAngle=asin((2*area)/(a*b));

        for(i=0;i<n;i++)
        {
            if(points[i].degAngle-mini<Eps)
                mini=points[i].degAngle;
            if(maxi-points[i].degAngle<Eps)
                maxi=points[i].degAngle;
        }
        printf("%.6lf %.6lf\n", mini*180.0/PI, maxi*180.0/PI);

    }
    return 0;
}
