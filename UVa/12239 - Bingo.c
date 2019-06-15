//Accepted
#include<stdio.h>
int main()
{
    freopen("12239.txt", "r", stdin);
    int n,b,ball[100],i,j,k,count,flag;
    while(scanf("%d %d",&n,&b) && n!=0 && b!=0)
    {
        flag=0;
        count=0;
        for(i=0;i<b;i++)
            scanf("%d",&ball[i]);
        for(i=0;i<=n;i++)
         {
            for(j=0;j<b-1;j++)
            {
              for(k=j;k<b;k++)
                {
                    if((ball[j]-ball[k]==i) || (ball[k]-ball[j]==i))
                    {
                        count++;
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    flag=0;
                    break;
                }
            }
         }
         if(count==n+1)
            printf("Y\n");
         else printf("N\n");
    }
    return 0;
}
