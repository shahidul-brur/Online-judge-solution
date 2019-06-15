//Accepted

#include<stdio.h>
#include<math.h>
int main()
{

        double h1,h2,h,amount,a,ans;
        int t,i;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
            scanf("%lf %lf %lf",&h1,&h2,&amount);
            h=(h1+h2)/3;
            if(h==0 || h1<=h)
                printf("0\n");
            else
            {
                a=h1-h;
                ans = floor(a * amount / h + 1e-8);
                printf("%.0lf\n",ans);
            }
        }
        return 0;
}
