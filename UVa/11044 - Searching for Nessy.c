//Accepted

#include<stdio.h>
int main()
{
    int t, i, a, b,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&a,&b);
        ans=(a/3)*(b/3);
        printf("%d\n",ans);
    }
    return 0;
}
