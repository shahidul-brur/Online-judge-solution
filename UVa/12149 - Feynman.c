//Accepted

#include<stdio.h>
int main()
{
    int n, ans;
    while(scanf("%d",&n) && n!=0)
    {
        ans=n*(n+1)*(2*n+1)/6;
        printf("%d\n",ans);
    }
    return 0;
}
