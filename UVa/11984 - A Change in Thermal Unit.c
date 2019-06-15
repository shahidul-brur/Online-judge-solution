//Accepted
#include<stdio.h>
int main()
{
    int t,c,d,i;
    float f,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&c,&d);
        f=9.0*c/5+32+d;
        ans=5*(f-32)/9;
        printf("Case %d: %.2f\n",i,ans);
    }
    return 0;
}
