//Accepted

#include<stdio.h>
int main()
{
    double n,ans;
    while(scanf("%lf",&n)&&n>=0)
    {
        if(n==1)
            printf("0%%\n");
        else
            printf("%.0lf%%\n",(n/4)*100);
    }
    return 0;
}
