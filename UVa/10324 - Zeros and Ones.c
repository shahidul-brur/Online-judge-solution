//Accepted

#include<stdio.h>
int main()
{
    freopen("10324.txt", "r", stdin);
    char str[1000010],ch;
    int n, s,e,i,j,tmp,flag,c=1;
    while(scanf("%s",&str)!=EOF)
    {
        scanf("%d",&n);
        printf("Case %d:\n",c);
        while(n--)
        {
            flag=1;
            scanf("%d %d",&s,&e);
            if(s>e)
            {
                tmp=s;
                s=e;
                e=tmp;
            }
            ch=str[s];
            for(i=s+1;i<=e;i++)
            {
                if(str[i]!=ch)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                printf("No\n");
            else if(flag==1)
                printf("Yes\n");
        }
        c++;
    }
    return 0;
}
