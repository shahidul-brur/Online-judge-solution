#include<stdio.h>
int main()
{
    int t, n, ans=0, i, bi,temp;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        while(n!=0)
        {
            temp=n;
            n=n/2;
            bi=temp%2;
            if(bi==1)
            {
                ans++;
            }
        }
          printf("Case %d: %d\n",i,ans);
          ans=0;
    }
    return 0;
}
