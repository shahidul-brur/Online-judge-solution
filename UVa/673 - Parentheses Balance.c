//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    int len,t,i,flag,fo,fc,to,tc,l;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
       gets(str);
       fo=fc=to=tc=0;
       flag=1;
       len=strlen(str);
       l=len-1;
       if(str[0]==')' || str[0]==']' || str[l]=='(' || str[l]=='[')
            flag=0;
        else
        {
            for(i=0;i<=l;i++)
            {
                if(i>0 && ((str[i]==')'&&str[i-1]=='[') || (str[i]==']'&&str[i-1]=='(')))
                {
                    flag=0;
                    break;
                }
                if(str[i]=='(')
                    fo++;
                else if(str[i]==')')
                    fc++;
                else if(str[i]=='[')
                    to++;
                else if(str[i]==']')
                    tc++;
            }
            if(fo!=fc || to!=tc)
                flag=0;
        }
        if(flag==1)
            printf("Yes\n");
        else if(flag==0)
            printf("No\n");
    }
    return 0;
}
