//Accepted
#include<stdio.h>
int main()
{
    //freopen("10370.txt", "r", stdin);
    int c,n,i,count,avg,sum,num[1005];
    float abv;
    scanf("%d",&c);
    while(c--)
    {
        sum=0;
        count=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        avg=sum/n;
        for(i=1;i<=n;i++)
            if(num[i]>avg)
            {
                count++;
            }
            abv=(float)count/n*100;
          printf("%.3f%%\n",abv);
    }
    return 0;
}
