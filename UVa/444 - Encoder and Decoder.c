//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("444.txt", "r", stdin);
    int len,i,v;
    char str[1000];
    while(gets(str))
    {
        len=strlen(str);
        if(len==0)
            printf("\n");
        else if(str[len-1]>='0'&&str[len-1]<='9')
        {
            for(i=len-1;(str[i]>='0' && str[i]<='9');i-=2)
            {
                v=(str[i]-'0')*10+str[i-1]-'0';
                if(v<32)
                {
                    v=v*10+str[i-2]-'0';
                    i--;
                }
                printf("%c",v);
            }
            printf("\n");
        }
        else
        {
            for(i=len-1;i>=0;i--)
            {
                v=str[i];
                if(v<100)
                    printf("%d%d",v%10,v/10);
                else if(v>99)
                    printf("%d%d%d",v%10,(v%100)/10,v/100);
            }
            printf("\n");
        }
    }
    return 0;
}
