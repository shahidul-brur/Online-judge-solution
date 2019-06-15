//Accepted
#include<stdio.h>
#include<math.h>
int main()
{
    freopen("10287.txt", "r", stdin);
    double L,r1,r2,r3,r4,root3;
    while(scanf("%lf",&L)!=EOF)
    {
        root3=sqrt(3);
        r1=L*root3/2.0;
        r2=L/(1+2.0/root3);
        r3=r1/2.0;
        r4=L/(2.0/root3+4.0/sqrt(7));
        printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);
    }
    return 0;
}
