#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10293.txt", "r", stdin);
    char str[100];
    int len,L=0,f[40],i,j,p=0;
    while(gets(str))
    {
        if(strcmp(str, "#")==0)
        {
            for(i=1;i<31;i++)
               if(f[i]>0)
                    printf("%d %d\n",i,f[i]);
            printf("\n");
        }
        else
        {
            for(i=0;i<=33;i++)
                f[i]=0;
            len=strlen(str);
            for(i=0;i<len;i++)
            {
                //if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
                while(str[i]!=' '&&str[i]!='?'&&str[i]!='!'&&str[i]!=','&&str[i]!='.')
                {
                    if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
                        L++;
                    i++;
                    if(i==len-1 || str[i]=='-')
                        break;
                }
                if(str[i]!='-')
                {
                    f[L]++;
                    L=0;
                }
                //}
            }

        }
    }
    return 0;
}
