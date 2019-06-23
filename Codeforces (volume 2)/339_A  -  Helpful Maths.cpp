#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[110];
    int i, len, f[5], a=0, b=0, c=0;
    f[1]=f[2]=f[3]=0;
    scanf("%s", s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]!='+')
         f[s[i]-'0']++;

    if(f[1]>0)
        a=1;
    if(f[2]>0)
        b=1;
    if(f[3]>0)
        c=1;


    for(i=0;i<f[1];i++)
    {
        if(i>0)
            printf("+");
        printf("1");

    }
    for(i=0;i<f[2];i++)
    {
        if(a==0)
        {
            if(i>0)
                printf("+");
        }
        else printf("+");
        printf("2");

    }
    for(i=0;i<f[3];i++)
    {
        if(a==0 && b==0)
        {
            if(i>0)
                printf("+");
        }
        else printf("+");
        printf("3");

    }
    printf("\n");
    return 0;
}