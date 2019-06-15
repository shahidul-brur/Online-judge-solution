//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    int n, ans,i,c=1;
    while(scanf("%d",&n) && n>=0)
    {
       for(i=0;i<16;i++)
       {
          if(n<=pow(2,i))
            {
                ans=i;
                break;
            }
       }
       printf("Case %d: %d\n",c,ans);
       c++;
    }
    return 0;
}
