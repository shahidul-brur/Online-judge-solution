//Accepted

#include<stdio.h>
#include<math.h>
#define pi acos(-1)
int main()
{
    int t, i;
    double r, asq, acr, ans;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf", &r);
        asq=4*r*r;
        acr=pi*r*r;
        ans=asq-acr;
        printf("Case %d: %0.2lf\n", i, ans);
    }
    return 0;
}
