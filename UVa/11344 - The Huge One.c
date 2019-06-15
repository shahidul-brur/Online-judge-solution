//Accepted

#include<stdio.h>
#include<string.h>
long Mod(char *num, long div)
{
    long long i,r=0,len;
    len=strlen(num);
    for(i=0;i<len;i++)
    {
        r=r*10+num[i]-'0';
        r=r%div;
    }
    return r;
}
int main()
{
    freopen("11344.txt", "r", stdin);
    char num[1010];
    long n, t,d[15],i,j,w;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%s",&num);
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
            scanf("%ld",&d[i]);
        w=1;
        for(i=1;i<=n;i++)
        {
            if(Mod(num, d[i])!=0)
            {
                w=0;
                break;
            }
        }
        if(w==1)
            printf("%s - Wonderful.\n",num);
        else printf("%s - Simple.\n",num);
    }
    return 0;
}
