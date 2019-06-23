//Accepted
#include <stdio.h>
#include <string.h>
int dgsum(int num)
{
    int sum=num;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int main()
{
    int t, i, n, generator[100003], s;
    memset(generator, 0, sizeof(generator));
    for(i=1;i<=99964;i++)
    {
        s=dgsum(i);
        if(generator[s]==0)
            generator[s]=i;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n", generator[n]);
    }
    return 0;
}
