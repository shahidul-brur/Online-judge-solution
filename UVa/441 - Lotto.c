//Accepted

#include<stdio.h>
int main()
{
    freopen("441.txt", "r", stdin);
    int n,i,j,num[20],temp,c=1,k,l,m,o;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(num[j]>num[j+1])
                {
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                }
            }
        }
        if(c!=1)
            printf("\n");
        for(i=1;i<=n-5;i++)
        {
            for(j=i+1;j<=n-4;j++)
            {
                for(k=j+1;k<=n-3;k++)
                {
                    for(l=k+1;l<=n-2;l++)
                    {
                        for(m=l+1;m<=n-1;m++)
                        {
                            for(o=m+1;o<=n;o++)
                                printf("%d %d %d %d %d %d\n",num[i],num[j],num[k],num[l],num[m],num[o])  ;
                        }
                    }
                }
            }
        }
        c++;
    }
    return 0;
}
