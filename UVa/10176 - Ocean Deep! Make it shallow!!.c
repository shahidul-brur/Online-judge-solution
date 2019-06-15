//Accepted

#include<stdio.h>
#include<string.h>
#include<math.h>
long square(long n)
{
    return n*n;
}
long bigmod(long b,long p,long m)
{
    if(b==0)
        return 0;
    else if (p == 0)
        return 1;
    else if (p%2 == 0)
        return square(bigmod(b,p/2,m)) % m;
    else
        return ((b % m) * bigmod(b,p-1,m)) % m;
}
int main()
{
    freopen("10176.txt", "r", stdin);
    char num[10100], temp[250], last;
    long long rem, len, decimal, i, p, d;
    while(scanf("%s",&num)!=EOF)
    {
        len=strlen(num);
        last=num[len-1];
        while(last!='#')
        {
            scanf("%s",temp);
            len=strlen(temp);
            last=temp[len-1];
            strcat(num, temp);
        }
        len=strlen(num);
        if(num[len-1]=='#')
            num[len-1]='\0';
        len=strlen(num);
        decimal=0;
        for(i=len-1, p=0;i>=0;i--, p++)
        {
            d=num[i]-'0';
            decimal+=d*bigmod(2, p, 131071);
        }
        if(decimal%131071==0)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
