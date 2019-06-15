#include<stdio.h>
int main()
{
    freopen("10286.txt", "r", stdin);
    double a,b;
    while(scanf("%lf",&a)!=EOF)
    {
        b=(9606*a)/9000;
        printf("%.10lf\n",b);
    }
    return 0;
}
