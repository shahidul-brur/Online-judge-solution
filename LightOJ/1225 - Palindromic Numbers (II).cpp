/**********************************************************
Status:     Accepted
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int isPallin(char *str)
{
    int len=strlen(str);
    for(int i=0;i<=len/2;i++)
    {
        if(str[i]!=str[len-1-i])
            return 0;
    }
    return 1;
}
int main()
{
    int t, cas;
    char num[15];
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s", num);
        if(isPallin(num))
            printf("Case %d: Yes\n", cas);
        else printf("Case %d: No\n", cas);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
