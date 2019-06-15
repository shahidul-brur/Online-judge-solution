//Accepted

#include<stdio.h>
int main()
{
    int n,i,sq[52];
    sq[0]=0;
    sq[1]=1;
    for(i=2;i<=50;i++)
        sq[i]=sq[i-1]+sq[i-2];
    while(scanf("%d",&n)&&n!=0)
    {
        printf("%d\n",sq[n+1]);
    }
    return 0;
}
