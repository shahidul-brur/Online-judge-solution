//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10293.txt", "r", stdin);
    char str[100];
    int len,L=0,f[40],i,j,p=0, hype=0;
    for(i=0;i<=33;i++)
        f[i]=0;
    while(gets(str))
    {
        if(strcmp(str, "#")==0)
        {
            for(i=1;i<31;i++)
               if(f[i]>0)
                    printf("%d %d\n",i,f[i]);
            printf("\n");
            for(i=0;i<=33;i++)
                f[i]=0;
            hype=0;
            L=0;
        }
        else
        {
            len=strlen(str);
            i=0;
            if(hype==1)
            {
                while(str[i]!=' '&&str[i]!='?'&&str[i]!='!'&&str[i]!=','&&str[i]!='.')
                {
                    L++;
                    i++;
                }
                f[L]++;
                hype=0;
            }
            L=0;
            for(;i<=len;i++)
            {
                if(i==len)
                {
                    f[L]++;
                    L=0;
                    break;
                }
                if(i==len-1 && str[i]=='-')
                {
                    hype=1;
                    break;
                }
                if(str[i]==' ' || str[i]=='?' || str[i]=='!' || str[i]==',' || str[i]=='.')
                {
                    f[L]++;
                    L=0;
                }
                else if(str[i]!='-' && str[i]!='\'')
                {
                    L++;
                }
            }

        }
    }
    return 0;
}
