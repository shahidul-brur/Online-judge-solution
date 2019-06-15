//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("445.txt", "r", stdin);
    int len,i,n,j;
    char str[150];
    while(gets(str))
    {
        if(strcmp(str,"")==0)
            printf("\n");
        else
        {
            len=strlen(str);
            for(i=0;i<len;i++)
            {
                n=0;
                if(str[i]=='!')
                    printf("\n");
                while(str[i]>='0' && str[i]<='9')
                {
                    n+=str[i]-'0';
                    i++;
                }
                for(j=1;j<=n;j++)
                {

                    if(str[i]=='b')
                        printf(" ");
                    else
                        printf("%c",str[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
