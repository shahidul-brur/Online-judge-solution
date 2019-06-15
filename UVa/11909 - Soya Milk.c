#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    //freopen("11909.txt", "r", stdin);
    int l,w,h,a,c=1;
    double ans,m,b,t;
    while(scanf("%d %d %d %d",&l,&w,&h,&a)!=EOF)
    {
        m=PI/180;
        b=l*tan(m*a)*0.5;
        printf("%lf\n", b);
        if(h-b>0)
        {
            ans=(double)l*w*(h-b);
            printf("%d %.3lf mL\n",c,ans);
        }
        else
        {

        }
        c++;
    }
    return 0;
}
