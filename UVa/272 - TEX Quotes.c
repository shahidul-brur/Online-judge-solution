#include<stdio.h>
#include<string.h>
int main()
{
    int len, i,j,flag=0;
    char str[10000];
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='"' && flag==0)
            {
                printf("``");
                flag=1;
            }
            else if(str[i]=='"' && flag==1)
            {
                printf("''");
                flag=0;
            }
            else
                printf("%c",str[i]);

        }
        printf("\n");
    }
    return 0;
}
