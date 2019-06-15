//Accepted

#include<stdio.h>
int main()
{
    //freopen("488.txt", "r",stdin);
    int t, a, b,i,j,k,l,m,n;
    scanf("%d\n",&t);
    for(n=1;n<=t;n++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        for(i=1;i<=a;i++)
        {
            for(j=0;j<i;j++)
            {
                printf("%d",i);
            }
            printf("\n");
        }
        for(k=i-2;k>=1;k--)
        {
            for(l=0;l<k;l++)
            {
                printf("%d",k);
            }
            printf("\n");
        }
        for(m=1;m<b;m++)
        {
            printf("\n");
            for(i=1;i<=a;i++)
            {
                for(j=0;j<i;j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            for(k=i-2;k>=1;k--)
            {
                for(l=0;l<k;l++)
                {
                    printf("%d",k);
                }
                printf("\n");
            }
        }
        if(n!=t) printf("\n");
    }
    return 0;
}
