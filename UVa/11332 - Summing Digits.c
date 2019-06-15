//Accepted

#include<stdio.h>
int main()
{
    long long int n,d,sum,r;
    while(scanf("%lld",&n)&&n!=0)
    {
          while(n>9)
            {
                sum=0;
                d=n;
                while(d!=0)
                {
                    r=d%10;
                    sum+=r;
                    d=d/10;
                }
                n=sum;
            }
            printf("%lld\n",n);
    }
    return 0;
}
