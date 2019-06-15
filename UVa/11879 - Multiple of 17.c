//Accepted

#include<stdio.h>
#include<string.h>
int mod(char *n)
{
    long long r=0,i,len;
    len=strlen(n);
    for(i=0;i<len;i++)
    {
        r=(10*r+n[i]-'0')%17;
    }
    return r;
}
int main()
{
    char num[200];
    long long rem;
    while(scanf("%s",&num)!=EOF)
    {
        if(num[0]=='0' && num[1]=='\0')
            break;
        rem=mod(num);
        if(rem==0)
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}
