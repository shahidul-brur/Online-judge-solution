#include<stdio.h>
int main()
{
    int t, n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=10)
        {
            a=0;
            b=n;
        }
        else
        {
            a=n-10;
            b=10;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
