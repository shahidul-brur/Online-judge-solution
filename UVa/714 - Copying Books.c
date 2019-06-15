#include<stdio.h>
int main()
{
    freopen("714.txt", "r", stdin);
    unsigned long long int t,m,k,p[510],i,j,sum,av,total;
    scanf("%llu",&t);
    while(t--)
    {
        sum=0;
        scanf("%llu %llu",&m,&k);
        for(i=1;i<=m;i++)
        {
            scanf("%llu\n",&p[i]);
            sum+=p[i];
        }
        //printf("%llu",sum);
        av=sum/k;
        j=1;
        for(i=1;i<k;i++)
        {
            total=p[j];
            for(j=j;total<=av;j++)
            {
                printf("%d ",p[j]);
                total+=p[j+1];
            }
            printf("/ ");
        }
        for(j=j;j<=m;j++)
        {
            printf("%d",p[j]);
            if(j<m)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
