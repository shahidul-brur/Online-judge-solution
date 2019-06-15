//Accepted


#include<stdio.h>
#include<string.h>
int main()
{
    char str[6];
    int len,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",&str);
        len=strlen(str);
        if(len==5)
            printf("3\n");
        else
        {
            if((str[0]=='o'&&str[1]=='n' ) || (str[0]=='o'&&str[2]=='e' )|| (str[1]=='n' && str[2]=='e'))
                printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
