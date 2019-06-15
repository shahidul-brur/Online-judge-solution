//Accepted

#include<stdio.h>
#include<math.h>
long factDigit(long num)
{
    double sum=0;
    int i;
    if(num==0)
        return 1;
    for(i=1;i<=num;i++)
    {
        sum+=log10(i);
    }
    return floor(sum)+1;
}
int main()
{
    long n,t;
    double s;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        s=factDigit(n);
        printf("%.lf\n",s);
    }
    return 0;
}
