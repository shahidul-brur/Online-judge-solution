//Accepted
#include<stdio.h>
int main()
{
    long long int t,a,b,x,y;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        if(a>=b && (a+b)%2==0 && (a-b)%2==0)
        {
            x=(a+b)/2;
            y=(a-b)/2;
            printf("%lld %lld\n",x,y);
        }

        else
            printf("impossible\n");
    }
    return 0;
}
