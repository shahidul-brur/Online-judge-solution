//Accepted

#include<stdio.h>
int main()
{
    unsigned long long int i,sum[50003],x;
    sum[0]=0;
    for(i=1;i<=50000;i++)
    {
        sum[i]=i*i*i+sum[i-1];
    }
    while(scanf("%llu",&x)!=EOF)
    {
        printf("%llu\n",sum[x]);
    }
    return 0;
}
