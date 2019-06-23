#include <stdio.h>
#include <string.h>
int main()
{
    int len;
    char s[25];
    scanf("%s", s);
    len=strlen(s);
    printf("%d\n", (len+1)*26 - len);
    return 0;
}