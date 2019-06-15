//Accepted

#include<stdio.h>
int main()
{
    long long int t,a,b,c,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a==b && b==c && c==d && d==a)
            printf("square\n");
        else if((a==c && b==d)||(a==b && c==d)||(a==d && b==c))
            printf("rectangle\n");
        else if(a+b+c>d && a+b+d>c && a+c+d>b && b+c+d>a)
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
    return 0;
}
