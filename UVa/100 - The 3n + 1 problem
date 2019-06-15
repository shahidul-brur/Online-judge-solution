//Accepted

#include<stdio.h>
int main()
{
    //freopen("100.txt", "r", stdin);
    long long int i,j,a,b,c,t,val,max;
    while(scanf("%lld %lld", &i,&j)!=EOF)
    {
        max=1;
        printf("%lld %lld ",i,j);
        if(i>j)
        {
            a=j;
            b=i;
        }
        else
        {
            a=i;
            b=j;
        }
        for(t=a;t<=b;t++)
        {
            c=t;
            val=1;
            while(c!=1)
            {
                if(c%2==1)
                {
                    c=3*c+1;
                    val++;
                }
                else if(c%2==0)
                {
                    c=c/2;
                    val++;
                }
                if(val>max)
                    max=val;
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}
