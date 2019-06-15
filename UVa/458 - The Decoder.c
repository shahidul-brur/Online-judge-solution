//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    int len,i;
    char str[10000];
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
            printf("%c",str[i]-7);
        printf("\n");
    }
    return 0;
}
