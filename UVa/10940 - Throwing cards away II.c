#include<stdio.h>
int main()
{
    int card[500005],i,j,n,m,temp;
    while(scanf("%d",&n) && n!=0)
    {
        m=n;
        for(i=1;i<=n;i++)
            card[i]=i;
        if(n==1)
            temp=1;
        for(j=1;j<n;j++)
        {
            temp=card[2];
                m--;
            for(i=1;i<m;i++)
                card[i]=card[i+2];
            card[m]=temp;
        }
        printf("%d\n",temp);
    }
    return 0;
}
