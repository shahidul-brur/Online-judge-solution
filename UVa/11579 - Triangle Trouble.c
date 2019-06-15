#include<stdio.h>
#include<math.h>
int main()
{
    freopen("11579.txt", "r", stdin);
    int t,n,i,j,k,flag;
    double side[10005],a,b,c,area,temp,s;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&side[i]);
        }

        for(i=1;i<n;i++)
        {
            for(j=1;j<=n-i;j++)
            {
                if(side[j]<side[j+1])
                {
                    temp=side[j];
                    side[j]=side[j+1];
                    side[j+1]=temp;
                }
            }
        }

        for(i=1;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<=n;k++)
                {

                    if(side[j]+side[k]>side[i])
                    {
                        s=(side[i]+side[j]+side[k])/2;
                        area=sqrt(s*(s-side[i])*(s-side[j])*(s-side[k]));
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            printf("0.00\n");
        else
            printf("%.2lf\n",area);
    }
    return 0;
}
