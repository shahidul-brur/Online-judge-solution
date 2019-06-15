//Accepted

#include<stdio.h>
int main()
{
    freopen("11479.txt", "r", stdin);
    long long int t,c,a,b,cas;
    scanf("%lld",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a+b<=c || b+c<=a || c+a<=b)
            printf("Case %lld: Invalid\n",cas);
        else if(a==b && b==c)
            printf("Case %lld: Equilateral\n",cas);
        else if((a==b && a!=c)||(b==c && b!=a)||(c==a && c!=b))
            printf("Case %lld: Isosceles\n",cas);
        else if(a!=b && b!=c && c!=a)
            printf("Case %lld: Scalene\n",cas);
    }
    return 0;
}
