#include<stdio.h>
int main()
{
    freopen("382.txt", "r", stdin);
    int n,i,j,sum,ans,len;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n) && n!=0)
        {
            len=0;
            sum=1;
            for(i=2;(i*i<=n && i!=n);i++)
            {
                if(n%i==0)
                {
                    sum+=i+n/i;
                }
            }
            ans=n;
            while(n!=0)
            {
                len++;
                n/=10;
            }
            for(i=1;i<=5-len;i++)
                printf(" ");
            if(ans==1)
                printf("%d  DEFICIENT\n",ans);
            else if(sum==ans)
               printf("%d  PERFECT\n",ans);
            else if(sum<ans)
                printf("%d  DEFICIENT\n",ans);
            else if(sum>ans)
                printf("%d  ABUNDANT\n",ans);
        }
        printf("END OF OUTPUT\n");
        return 0;
}
