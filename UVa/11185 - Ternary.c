//Accepted

#include<stdio.h>
int main()
{
    long long int deci,bin,rem,p;
    while(scanf("%lld",&deci) && deci>=0){
    bin=0;
    p=1;
    while(deci!=0)
    {
        rem=deci%3;
        bin=bin+p*rem;
        deci=deci/3;
        p=p*10;
    }
    printf("%lld\n",bin);
    }
    return 0;
}
