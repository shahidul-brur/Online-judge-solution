//Accepted

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    freopen("1387.txt", "r",stdin);
    char oper[1000];
    int sum,t,n,i,c=1;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        getchar();
        printf("Case %d:\n",c);
        while(n--)
         {
            gets(oper);
            if(oper[0]=='d')
            {
                for(i=7;i<strlen(oper);i++)
                    oper[i-7]=oper[i];
                oper[i]='\0';
                sum=sum+atoi(oper);
            }
            else if(oper[0]=='r')
                printf("%d\n",sum);
         }
         c++;
    }
    return 0;

}

