//Accepted

#include<stdio.h>
int main()
{
    long long int n,m;
    while(scanf("%lld",&n) && n!=0)
    {
        m=n;
        if(n>100)
            n=n-10;
        else
        {
            n=91;
        }
        printf("f91(%lld) = %lld\n",m,n);
    }
    return 0;
}
