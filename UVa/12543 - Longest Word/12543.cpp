//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("12543.txt", "r", stdin);
    int len, i, longest=0, L, j;
    char txt[120], word[150], neew[150], ch;
    while(scanf("%s",&txt)!=EOF)
    {
        if(strcmp("E-N-D", txt)==0)
        {
            break;
        }
        len=strlen(txt);
        j=0;
        for(i=0;i<len;i++)
        {
            if(txt[i]=='-' || (txt[i]>='a' && txt[i]<='z'))
            {
                neew[j++]=txt[i];
            }
            else if(txt[i]>='A' && txt[i]<='Z')
            {
                neew[j++]=txt[i]-'A' + 'a';
            }
            else
            {
                neew[j]='\0';
                j=0;
                //puts(neew);
                L=strlen(neew);
                if(L>longest)
                {
                    longest=L;
                    strcpy(word, neew);
                }
            }
            if(i==len-1)
            {
                neew[j]='\0';
                j=0;
                //puts(neew);
                L=strlen(neew);
                if(L>longest)
                {
                    longest=L;
                    strcpy(word, neew);
                }
            }

        }
    }
    puts(word);
    return 0;
}
