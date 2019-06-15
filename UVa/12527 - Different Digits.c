//Accepted
#include<stdio.h>
int main()
{
    int n,m,i,j,d,r,count,flag;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        count=0;
        for(i=n;i<=m;i++)
        {
          if(i<10)
            count++;
          else if(i>=10&&i<=99)
          {
              if(i%10!=(i/10)%10)
                count++;
          }
          else if(i>=100 && i<999)
          {
              if(i%10!=(i/10)%10 && i%10!=i/100 && (i/10)%10!=i/100)
                count++;
          }
          else if(i>=1000 && i<=9999)
          {
              if(i%10!=(i/10)%10 && i%10!=(i/100)%10  && i%10!=i/1000 && (i/10)%10!=(i/100)%10 && (i/10)%10!=i/1000 && (i/100)%10!=i/1000)
                count++;
          }
        }
        printf("%d\n",count);
    }
    return 0;
}
