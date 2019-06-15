//Accepted

#include<stdio.h>
int main()
{
    int t,i,n,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        ans=(((((n*567)/9+7492)*235)/47-498)/10)%10;
        if(ans<0) ans=0-ans;
        printf("%d\n",ans);
    }
    return 0;
}
