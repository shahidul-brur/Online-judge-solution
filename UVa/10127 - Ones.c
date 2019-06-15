#include<stdio.h>
#include<stdio.h>
long Mod(long size, long d)
{
    long long i,r=0,len;
    char num[25005];
    for(i=0;i<size;i++)
        num[i]='1';
    num[i]='\0';
    len=strlen(num);
    for(i=0;i<len;i++)
    {
        r=r*10+num[i]-'0';
        r=r%d;
    }
    return r;
}
int main()
{
    long n,i,ans;
    while(scanf("%ld",&n)!=EOF)
    {

        for(i=1;i<=25000;i++)
        {
            if(Mod(i, n)==0)
            {
                ans=i;
                break;
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
