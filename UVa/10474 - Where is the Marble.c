//Accepted

#include<stdio.h>
int main()
{
    //freopen("10474.txt", "r", stdin);
    int n,q,mar[10010],qur[10010],i,j,found,temp,cas=1;
    while(scanf("%d %d",&n,&q) && (n!=0 || q!=0))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&mar[i]);

        for(j=1;j<=q;j++)
            scanf("%d",&qur[j]);
        for(i=0;i<n;i++)
            for(j=1;j<n;j++)
                if(mar[j]>mar[j+1])
                {
                    temp=mar[j];
                    mar[j]=mar[j+1];
                    mar[j+1]=temp;
                }
        printf("CASE# %d:\n",cas);
        for(j=1;j<=q;j++)
         {
            found=0;
            for(i=1;i<=n;i++)
            {
                if(qur[j]==mar[i])
                {
                    found=1;
                    break;
                }
                else found=0;
            }
            if(found==1)
                printf("%d found at %d\n",qur[j],i);
            else if(found==0)
                printf("%d not found\n",qur[j]);
        }
        cas++;
    }
    return 0;
}
