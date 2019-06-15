//Accepted
#include<stdio.h>
#include<string.h>
long mod(char *n,long d)
{
    long long r=0,i,len;
    len=strlen(n);
    for(i=0;i<len;i++)
    {
        r=(10*r+n[i]-'0')%d;
    }
    return r;
}
int main()
{
    char num[2500];
    long div,rem,t;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&div);
        scanf("%s",&num);
        rem=mod(num,div);
        printf("%ld\n",rem);
    }
    return 0;
}
