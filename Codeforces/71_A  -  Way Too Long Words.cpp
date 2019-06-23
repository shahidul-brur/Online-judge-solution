#include<stdio.h>
#include<string.h>

int main()
{
    int n, len, i;
    char s[105];
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%s", s);
        len = strlen(s);
        if(len<=10)
            printf("%s\n", s);
        else
        {
            printf("%c%d%c\n", s[0], len-2, s[len-1]);
        }
    }
    return 0;
}
