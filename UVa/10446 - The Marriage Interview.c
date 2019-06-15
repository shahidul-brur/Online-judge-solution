#include<stdio.h>
int trib(int n, int back, int count)
{

    int sum=0;
    int i;


    if(n<=0) return 0;

    if(n==1) return 1;

    for(i=1;i<=back;i++)
    {
        count++;
        sum+=trib(n-i,back,count);
    }

    return count;

}



int main()

{
    int a, b,count;
    while(scanf("%d %d",&a,&b)&&a<=60)
    {
        count=0;
        printf("%d\n",trib(a,b,count));
    }
    return 0;
}
