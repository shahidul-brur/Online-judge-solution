#include<stdio.h>
int gcd(int a,int b)
{
    int min,i;
    if(a<b)
        min=a;
    else
        min=b;
    for(i=min;i>=1;i--)
        if(a%i==0 && b%i==0)
            return i;
}
int main()
{
    freopen("11388.txt", "r", stdin);
    int t,a,b,G,L,i,j,flag,r,f[100000],k;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d %d",&G,&L);
        j=0;
        for(i=1;i<=L/i;i++)
        {
            if(L%i==0)
            {
                j++;
                f[j]=i;
            }
        }
        k=j;
        for(i=j;i>=1;i--)
        {
            k++;
            f[k]=L/f[j];
        }
        for(i=1;i<=k;i++)
            printf("%d ",f[i]);
        for(i=1;i<k;i++)
        {
            for(j=i+1;j<=k;j++)
            {
                if(f[i]/G==L/f[j])
                {
                    a=f[i];
                    b=f[j];
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            printf("-1\n");
        else printf("%d %d\n",a,b);
    }
    return 0;
}
