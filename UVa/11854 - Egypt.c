//Accepted

#include<stdio.h>
int main()
{
    long long int a,b,c;
    while(scanf("%lld %lld %lld",&a,&b,&c) && (a!=0 || b!=0 || c!=0))
    {
        a*=a;
        b*=b;
        c*=c;
        if(a+b==c || b+c==a || c+a==b)
            printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
