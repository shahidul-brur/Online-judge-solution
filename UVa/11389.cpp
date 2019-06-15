//Accepted
#include <stdio.h>
int main()
{
    int n, d, r, morning[110], evening[110], i, j, k, tmp;
    long long total;
    while(scanf("%d %d %d", &n, &d, &r)!=EOF)
    {
        if(n==0 && d==0 && r==0)
            break;
        for(i=1;i<=n;i++)
            scanf("%d",&morning[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&evening[i]);
        for(i=1;i<=n;i++)
          {
              for(j=1;j<n;j++)
              {
                  if(morning[j]>morning[j+1])
                  {
                      tmp=morning[j];
                      morning[j]=morning[j+1];
                      morning[j+1]=tmp;
                  }
              }
          }
        for(i=1;i<=n;i++)
          {
              for(j=1;j<n;j++)
              {
                  if(evening[j]<evening[j+1])
                  {
                      tmp=evening[j];
                      evening[j]=evening[j+1];
                      evening[j+1]=tmp;
                  }
              }
          }
          total=0;
        for(i=1;i<=n;i++)
        {
            if(morning[i]+evening[i]>d)
                total=total+(morning[i]+evening[i]-d)*r;
        }
        printf("%lld\n",total);
    }

    return 0;
}
