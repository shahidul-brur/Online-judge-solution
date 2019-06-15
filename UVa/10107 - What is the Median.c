#include<stdio.h>
int main()
{
    freopen("10107.txt", "r", stdin);
    int n=2,i,j,median,num[10005],temp,nu;
    num[0]=0;
    scanf("%d",&num[1]);
    printf("%d\n",num[1]);
    while(scanf("%d",&nu)!=EOF)
    {
        if(nu>=num[n-1])
            num[n]=nu;
        else if(nu<num[n-1] && nu>=num[n-2])
        {
            num[n]=num[n-1];
            num[n-1]=nu;
        }
        else
        {
            for(i=1;i<n;i++)
            {
                if(nu<=num[i]&&nu>=num[i-1])
                {
                    for(j=i;j<n;j++)
                    {
                        temp=num[j];
                        num[j]=nu;
                        nu=temp;
                    }
                    num[n]=nu;
                    break;
                }
            }
        }

        if(n%2==1)
            median=num[n/2+1];
        else
            median=(num[n/2]+num[n/2+1])/2;
        printf("%d\n",median);
        n++;
    }
    return 0;
}
