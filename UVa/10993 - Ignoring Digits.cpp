#include<stdio.h>
int main()
{
    long F,N,allow[12],i,j,mul,ans,flag;
    while(scanf("%ld %ld",&F,&N)==2)
    {
        if(F==0 && N==0)
            break;
        for(i=0;i<10;i++)
            allow[i]=i;
        flag=1;
        while(F>0)
        {
            allow[F%10]=F%10;
            F/=10;
        }
        for(i=1;N)
    }
}
