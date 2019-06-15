//Accepted

#include<stdio.h>
int main()
{
    int r,n,i,c=1,ans,s;
    while(scanf("%d %d",&r,&n)&&(r!=0||n!=0))
    {
        s=n;
        ans=0;
        if(s<r)
        {
            for(i=1;i<=26;i++)
            {

                ans++;
                s+=n;
                if(s>=r)
                    break;
            }
        }
        if(s<r)
            printf("Case %d: impossible\n",c);
        else
            printf("Case %d: %d\n",c,ans);
        c++;

    }
    return 0;
}
