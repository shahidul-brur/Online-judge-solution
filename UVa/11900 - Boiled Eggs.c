//Accepted

#include<stdio.h>
int main()
{
    freopen("11900.txt", "r", stdin);
    int t,n,egg[40],p,q,i,c,count,wgt,temp;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        count=wgt=temp=0;
        scanf("%d %d %d",&n,&p,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&egg[i]);

        for(i=1;i<=n;i++)
        {
            temp+=egg[i];
            if(temp>q || count==p)
                break;
            if(wgt+egg[i]<=q && count<p)
            {
                wgt+=egg[i];
                count++;
            }
        }
        printf("Case %d: %d\n",c,count);
    }
    return 0;
}
