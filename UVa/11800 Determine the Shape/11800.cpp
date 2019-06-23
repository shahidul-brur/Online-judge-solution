//Accepted
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int sqr(int n)
{
    return n*n;
}
typedef struct point
{
    int x;
    int y;
    double angle;
};

bool operator < (point A, point B)
{
    if(A.x == B.x) return (A.y<B.y);
    return (A.x<B.x);
}

bool cmp(point A, point B)
{
	return A.angle < B.angle;
}

double getAngle(point p)
{
    return atan2(p.y, p.x);
}
int main()
{
    //freopen("11800.txt", "r", stdin);
    int i, index, t, cas;
    int a, b, c, d, c1, c2;
    point lowestPoint;
    point points[5];
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        for(i=0;i<4;i++)
            scanf("%d %d", &points[i].x, &points[i].y);

    lowestPoint=points[0];
    index=0;
    for(i=1;i<4;i++)
    {
        if(points[i] < lowestPoint)
            lowestPoint=points[i], index = i;
    }

    swap(points[index], points[0]);

    for(i=0;i<4;i++)
        points[i].x-= lowestPoint.x, points[i].y -= lowestPoint.y;

    for(i=1;i<4;i++)
        points[i].angle=getAngle(points[i]);
    sort(points+1, points + 4, cmp);
    a=sqr(points[0].x-points[1].x) + sqr(points[0].y-points[1].y);
    b=sqr(points[1].x-points[2].x) + sqr(points[1].y-points[2].y);
    c=sqr(points[2].x-points[3].x) + sqr(points[2].y-points[3].y);
    d=sqr(points[3].x-points[0].x) + sqr(points[3].y-points[0].y);
    c1=sqr(points[0].x-points[2].x) + sqr(points[0].y-points[2].y);
    c2=sqr(points[1].x-points[3].x) + sqr(points[1].y-points[3].y);


    if(a==b && b==c && c==d && d==a)
    {
        if(a+b == c1 && c+d==c2)
            printf("Case %d: Square\n", cas);
        else
            printf("Case %d: Rhombus\n", cas);
    }
    else if(a==c && b==d)
    {
        if(a+b ==c1 && c+d==c2)
            printf("Case %d: Rectangle\n", cas);
        else
            printf("Case %d: Parallelogram\n", cas);
    }
    else if(((points[1].y-points[0].y)*(points[3].x-points[2].x) == (points[1].x-points[0].x)*(points[3].y-points[2].y))||((points[2].y-points[1].y)*(points[3].x-points[0].x) == (points[2].x-points[1].x)*(points[3].y-points[0].y)))
    {
        printf("Case %d: Trapezium\n", cas);
    }
    else
        printf("Case %d: Ordinary Quadrilateral\n", cas);

    }
    return 0;
}
