#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void ToDeci(char *from, int base, char *deci)
{
    int len=strlen(from);
    int i, p, j;
    for(i=len-1,p=0;i>=0;i--)
    {
        if(from[i]>='0' && from[i]<='9')
            to+=(from[i]-'0')*pow(base, p);
        else
            to+=(from[i]-'A'+10)*pow(base, p);
        p++;
    }
}
void rev(char *from, char *to)
{
    int len=strlen(from);
    int i;
    for(i=0;i<len;i++)
    {
        to[i]=from[len-1-i];
    }
    to[i]='\0';
}
void printConvertedBase(long long deci, int base)
{
    if(base==10)
    {
        printf("%lld", deci);
    }
    else
    {
        char ans[15], Ans[15];
        int rem, div=deci, i=0;
        while(div>0)
        {
            rem=div%base;
            div/=base;
            if(rem<=9)
                ans[i++]=rem+'0';
            else
                ans[i++]=rem-10+'A';
        }
        ans[i]='\0';
        if(i==0)
            strcpy(ans, "0");
        rev(ans, Ans);
        printf("%s", Ans);
    }
}
int main()
{
    freopen("355.txt", "r", stdin);
    char from[15], to[15], deci[500];
    int baseFrom, baseTo, len, invalid,i,d;
    while(scanf("%d", &baseFrom)!=EOF)
    {
        scanf("%d %s", &baseTo, from);
        invalid=0;
        len=strlen(from);
        for(i=0;i<len;i++)
        {
            if(from[i]>='0' && from[i]<='9')
                d=from[i]-'0';
            else
                d=from[i]-'A'+10;
            if(d>=baseFrom)
            {
                invalid=1;
                break;
            }
        }
        if(invalid==1)
            printf("%s is an illegal base %d number\n", from, baseFrom);
        else
        {
            ToDeci(from, baseFrom, deci);
            printf("%s base %d = ", from, baseFrom);
            printConvertedBase(deci, baseTo);
            printf(" base %d\n", baseTo);
        }
    }
    return 0;
}
