//Accepted

#include<stdio.h>
int main()
{
    double income,tax,rest;
    int t,c;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lf",&income);
        if(income<=180000)
            tax=0.0;
        else if(income>180000)
        {
            rest=income-180000;
            if(rest<=300000)
            {
                tax=rest*0.10;
                if(tax<2000)
                    tax=2000;
                tax=ceil(tax);
            }
            else if(rest>300000)
            {

                tax=300000.0*0.10;
                tax=ceil(tax);
                rest-=300000;
                if(rest<=400000)
                {
                    tax+=rest*0.15;
                    tax=ceil(tax);
                }
                else if(rest>400000)
                {
                    tax+=400000.0*0.15;
                    tax=ceil(tax);
                    rest-=400000;
                    if(rest<=300000)
                    {
                        tax+=rest*0.20;
                        tax=ceil(tax);
                    }
                    else if(rest>300000)
                    {
                        tax+=300000.0*0.20;
                        tax=ceil(tax);
                        rest-=300000;
                        tax+=rest*0.25;
                        tax=ceil(tax);
                    }
                }
            }
        }

        printf("Case %d: %.0lf\n",c,tax);
    }
    return 0;
}
