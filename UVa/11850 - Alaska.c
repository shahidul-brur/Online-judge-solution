//Accepted
#include<stdio.h>
int main()
{
    long long int n, i,j, station[1435],temp,flag;
    while(scanf("%lld",&n) && n!=0)
    {
        flag=1;
        for(i=0;i<n;i++)
            scanf("%lld",&station[i]);
        for(i=0;i<n;i++)
          {
            for(j=0;j<n-1;j++)
            if(station[j]>station[j+1])
            {
                temp=station[j];
                station[j]=station[j+1];
                station[j+1]=temp;
            }
          }
            for(i=0;i<n-1;i++)
                {
                    if((station[i+1]-station[i])>200)
                    {
                        flag=0;
                        break;
                    }
                }
                if(2*(1422-station[n-1])>200)
                    flag=0;
                if(flag==0)
                    printf("IMPOSSIBLE\n");
                else if(flag==1)
                    printf("POSSIBLE\n");
    }
    return 0;
}
