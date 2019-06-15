//Accepted

#include<stdio.h>
int main()
{
    int t, n,i,count[11],num,rem;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<=9;i++)
            count[i]=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            num=i;
            while(num!=0)
            {
                rem=num%10;
                count[rem]++;
                num/=10;
            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",count[0],count[1],count[2],count[3],count[4],count[5],count[6],count[7],count[8],count[9]);
    }
    return 0;
}
