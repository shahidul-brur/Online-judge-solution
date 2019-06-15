//Accepted but not submitted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("12403.txt", "r",stdin);
    char oper[1000];
    int sum=0,t,i;
    scanf("%d",&t);
    t=t+1;
    while(t--)
    {
      gets(oper);
        if(oper[0]=='d')
        {
            for(i=7;i<strlen(oper);i++)
                oper[i-7]=oper[i];
            sum=sum+atoi(oper);
        }
        else if(oper[0]=='r')
            printf("%d\n",sum);
    }
    return 0;

}
