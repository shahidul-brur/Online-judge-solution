//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("12243.txt", "r", stdin);
    int i, len;
    char sen[1500], ch, y, s;
    while(gets(sen))
    {
        if(sen[0]=='*' && sen[1]=='\0')
            break;
        len=strlen(sen);
        ch=sen[0];
        if(ch>='A' && ch<='Z')
            ch=ch-'A'+'a';
        y=1;
        for(i=1;i<len;i++)
        {
            if(sen[i]==' ')
            {
                s=sen[i+1];
                if(s>='A' && s<='Z')
                    s=s-'A'+'a';
                if(s!=ch)
                {
                    y=0;
                    break;
                }
            }
        }
        if(y==1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
