//Accepted
#include<stdio.h>
int main()
{
    //freopen("11057.txt", "r", stdin);
    long long int n, p[10010],m,i,j,a,b,min;
    while(scanf("%lld",&n)!=EOF)
    {
        min=999999;
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);
        scanf("%lld\n",&m);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(p[i]+p[j]==m && abs(p[i]-p[j])<min)
                {
                  min=abs(p[i]-p[j]);
                  if(p[i]>p[j])
                  {
                      a=p[j];
                      b=p[i];

                  }
                  else
                  {
                      a=p[i];
                      b=p[j];
                  }
                }
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n",a,b);
        printf("\n");
    }
    return 0;
}
