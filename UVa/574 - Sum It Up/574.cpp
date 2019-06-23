//status WA

#include <stdio.h>
int main()
{
    freopen("574.txt", "r", stdin);
    int total, n, num[14], i, sum, j, cnt, add[14], a, k, taken[400], combine, repeat, t, self, temp;
    while(scanf("%d", &total)!=EOF)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d", &num[i]);
        printf("Sums of %d:\n", total);
        cnt=t=self=0;
        for(i=0;i<n;i++)
        {
            if(num[i]==total && self==0)
            {
                printf("%d\n", num[i]);
                self=1;
                cnt++;
            }
            else if(num[i]<total)
            {
               sum=num[i];
               a=0;
               add[a++]=num[i];
               for(j=i+1;j<n;j++)
                {
                    if(sum+num[j]==total)
                    {
                        combine=0;
                        repeat=0;
                        for(k=0;k<a;k++)
                            combine=combine*10+add[k];
                        combine=combine*10+num[j];
                        for(k=0;k<t;k++)
                        {
                            if(taken[k]==combine)
                            {
                                repeat=1;
                                break;
                            }
                        }
                        if(repeat==0)
                        {
                            for(k=0;k<a;k++)
                                printf("%d+",add[k]);
                            printf("%d\n", num[j]);
                            taken[t++]=combine;
                            cnt++;
                        }
                    }
                    else if(sum+num[j]<total)
                    {
                        temp=sum;
                        sum+=num[j];
                        add[a++]=num[j];
                    }
                }
            }
        }
        if(cnt==0)
            printf("NONE\n");
    }
    return 0;
}
