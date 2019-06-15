#include<stdio.h>
int main()
{
    //freopen("10935.txt", "r", stdin);
    int card[150],i,j,n,flag,k,m,temp,c=1;
    while(scanf("%d",&n) && n!=0)
    {
        m=n;
        for(i=1;i<=n;i++)
            card[i]=i;
        if(n==1)
            temp=1;
        printf("Discarded cards:");
        for(j=1;j<n;j++)
        {
            printf(" %d",card[1]);
            if(j!=n-1)
                printf(",");
            temp=card[2];
                m--;
            for(i=1;i<m;i++)
                card[i]=card[i+2];
            card[m]=temp;
        }
        printf("\nRemaining card: %d\n",temp);
        c++;
    }
    return 0;
}
