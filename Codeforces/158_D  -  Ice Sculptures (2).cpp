#include<stdio.h>
int arr[20003],sum[20003];
int main()
{
    int n,i,j,max1,ans;
    bool d;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    d=0;
    for (i=1;i<=n;i++)
    {
        if (n%i||(n/i<3)) continue;
        for (j=0;j<i;j++) sum[j]=0;
        for (j=0;j<n;j++)
        {
            sum[j%i]+=arr[j];
        }
        max1=sum[0];
        for (j=1;j<i;j++)
        {
            if (sum[j]>max1) max1=sum[j];
        }
        if (!d)
        {
            ans=max1;
            d=1;
        }
        else if (max1>ans) ans=max1;
    }
    printf("%d\n",ans);
    return 0;
}