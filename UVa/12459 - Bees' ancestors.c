//Accepted

#include<stdio.h>
int main()
{
    unsigned long long int n,i,sq[85];
    sq[1]=1;
    sq[2]=2;
    for(i=3;i<=80;i++)
        sq[i]=sq[i-1]+sq[i-2];
    while(scanf("%llu",&n)&&n!=0)
    {
        printf("%llu\n",sq[n]);
    }
    return 0;
}
