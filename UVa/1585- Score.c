//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("1585.txt", "r", stdin);
    int t,len,i,total,mark[100];
    char str[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str);
        len=strlen(str);
        total=0;
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                if(str[i]=='O')
                    mark[i]=1;
                else mark[i]=0;
            }
            else if(i>0)
            {
                if(str[i]=='O' && str[i-1]=='O')
                    mark[i]=1+mark[i-1];
                else if(str[i]=='O' && str[i-1]!='O')
                    mark[i]=1;
                else if(str[i]!='O')
                    mark[i]=0;
            }
            total+=mark[i];
        }
        printf("%d\n",total);
    }
    return 0;
}
