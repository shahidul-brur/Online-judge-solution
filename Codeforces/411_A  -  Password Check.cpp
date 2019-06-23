#include<stdio.h>
#include<string.h>
int main()
{
    char pass[100];
    int len,i,fs=0,sc=0,th=0,fr=0;
    gets(pass);
    len=strlen(pass);
    if(len>=5) fs=1;
    for(i=0;i<len;i++)
    {
       if(pass[i]>='A' && pass[i]<='Z')
        {
            sc=1;
            break;
        }
    }
    for(i=0;i<len;i++)
    {
       if(pass[i]>='a' && pass[i]<='z')
        {
            th=1;
            break;
        }
    }
    for(i=0;i<len;i++)
    {
       if(pass[i]>='0' && pass[i]<='9')
        {
            fr=1;
            break;
        }
    }
    if(fs==1&&sc==1&&th==1&&fr==1) printf("Correct\n");
    else printf("Too weak\n");
    return 0;
}