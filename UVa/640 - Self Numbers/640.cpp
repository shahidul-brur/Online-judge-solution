//Accepted
#include <stdio.h>
#include <string.h>
long generator[1000003];
long dgsum(long num)
{
    long sum=num;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int main()
{
    long i, s;
    memset(generator, 0, sizeof(generator));
    s=0;
    for(i=1;s<=1000000;i++)
    {
        s=dgsum(i);
        if(s>1000000)
            break;
        if(generator[s]==0)
            generator[s]=i;
    }
   for(i=1;i<=1000000;i++)
   {
        if(generator[i]==0)
            printf("%ld\n", i);
    }
    return 0;
}
