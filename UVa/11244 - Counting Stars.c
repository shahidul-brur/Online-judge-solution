#include<stdio.h>
struct symbole{
char ch[110];
};
int main()
{
    freopen("11244.txt", "r", stdin);
    int m,n,i,j,count,flag,star;
    struct symbole in[105];
    while(scanf("%d %d",&n,&m))
    {
        count=0;
        if(n==0 && m==0)
           break;
        for(i=0;i<n;i++)
            scanf("%s",&in[i].ch);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                star=0;
                if(in[i].ch[j]=='*')
                {
                    star=flag=1;
                    if(j!=m-1)
                    {
                        if(in[i].ch[j+1]=='*')
                            flag=0;
                    }

                    if(j>0)
                    {
                        if(in[i].ch[j-1]=='*')
                        flag=0;
                    }

                    if(i>0)
                    {
                    if(in[i-1].ch[j]=='*')
                        flag=0;
                    }

                    if(i!=n-1)
                    {
                    if(in[i+1].ch[j]=='*')
                        flag=0;
                    }

                    if(i>0 && j!=m-1)
                    {
                    if(in[i-1].ch[j+1]=='*')
                        flag=0;
                    }

                    if(i>0 && j>0)
                    {
                    if(in[i-1].ch[j-1]=='*')
                        flag=0;
                    }

                    if(i!=n-1 && j!=m-1)
                    {
                        if(in[i+1].ch[j+1]=='*')
                            flag=0;
                    }

                    if(j>0 && i!=n-1)
                    {
                        if(in[i+1].ch[j-1]=='*')
                            flag=0;
                    }
                }
                if(flag==1&&star==1)
                    count++;
            }
        }

        printf("%d\n",count);
    }
    return 0;
}

