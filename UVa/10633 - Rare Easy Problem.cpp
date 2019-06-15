//Accepted
#include<stdio.h>
int main()
{
    unsigned long long int num;
    while(scanf("%llu",&num)&&num!=0)
    {
        if((num*10/9)%10==0)
            printf("%llu %llu\n",num*10/9-1,num*10/9);
        else
            printf("%llu\n",num*10/9);
    }
    return 0;
}
