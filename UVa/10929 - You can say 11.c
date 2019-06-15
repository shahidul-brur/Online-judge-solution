//Accepted

#include<stdio.h>
#include<string.h>
long long mod(char *n)
{
    long long i,len,r=0;
    len=strlen(n);
    for(i=0;i<len;i++)
    {
        r=(r*10+(n[i]-'0'))%11;
    }
    return r;
}
int main()
{
    freopen("10929.txt", "r",stdin);
    long long rem;
    char n[1010];
    while(gets(n))
    {
        if(n[0]=='0' && n[1]=='\0')
            break;
        rem=mod(n);
        if(rem==0)
            printf("%s is a multiple of 11.\n",n);
        else
            printf("%s is not a multiple of 11.\n",n);
    }
    return 0;
}
