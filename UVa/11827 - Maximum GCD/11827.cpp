//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int GCD(int a, int b)
{
    if(a==0)
        return b;
    return GCD(b%a, a);
}
int main()
{
    freopen("11827.txt", "r", stdin);
    int t, num[102], maxi, i, j, len, n, d, g;
    char number[700];
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        gets(number);
        len=strlen(number);
        if(len==0)
            t++;
        n=0;
        for(i=0;i<len;i++)
        {
            while(number[i]==' ')
                i++;
            d=0;
            while(number[i]>='0' && number[i]<='9')
            {
                d=d*10+number[i]-'0';
                i++;
            }
            num[n++]=d;
        }
        maxi=1;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                g=GCD(num[i], num[j]);
                if(g>maxi)
                    maxi=g;
            }
        }
        if(n>0)
        printf("%d\n", maxi);
    }
    return 0;
}
