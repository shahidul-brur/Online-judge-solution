//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    freopen("113.txt", "r", stdin);
    double n,p,k;
    while(scanf("%lf %lf",&n,&p)!=EOF)
    {
        printf("%.0lf\n",pow(p,1/n));
    }
    return 0;
}
