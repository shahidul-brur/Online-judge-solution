#include <stdio.h>
#include <math.h>

int main()
{
    int t, x, y, r;
    double d, m, M;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&r);
        d=sqrt(x*x + y*y);
        m=r-d;
        M=r+d;
        printf("%.2lf %.2lf\n", m, M);
    }

    return 0;
}
