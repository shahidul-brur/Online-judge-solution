#include<stdio.h>
int main()
{
    int n, k, num[110], i,ans=0,in,l,flag=0,dig;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        in=num[i];
        for(l=0;l<=k;l++)
        {
            while(in!=0)
            {
                dig=in%10;
                if(dig==l)
                {
                   flag++;
                   break;
                }
                in=in/10;
            }
            in=num[i];
        }
        if(flag==(k+1)) ans++;
        flag=0;
    }
    printf("%d\n",ans);
    return 0;
}