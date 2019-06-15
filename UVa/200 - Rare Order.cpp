/**********************************************************
Status:     A
Problem:    UVa : 200 - Rare Order
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 28 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    //freopen("200.txt", "r", stdin);
    char str[10000][25], order[60];
    int seq[28], i, j, len, value, s=0, start=28, finish, maxi=0;
    while(scanf("%s", str[s])!=EOF)
    {
        if(str[s][0]=='#')
            break;
        len=strlen(str[s]);
        if(len>maxi)
            maxi=len;
        s++;
    }
    memset(seq, 0, sizeof(seq));
    for(i=0;i<59;i++)
        order[i]='.';
    order[i]='\0';
    seq[str[s][0]-'A']=28;

    for(j=0;j<maxi;j++)
    {
        for(i=1;i<s;i++)
        {
            if(j<strlen(str[i-1]) && j<strlen(str[i]))
            {
                if(j==0)
                {
                    if(str[i-1][j]!=str[i][j])
                    {
                        if(seq[str[i-1][j]-'A']!=0)
                            seq[str[i][j]-'A']=seq[str[i-1][j]-'A']+1;
                        else if(seq[str[i][j]-'A']!=0)
                            seq[str[i-1][j]-'A']=seq[str[i][j]-'A']-1;
                    }
                    else if(str[i-1][j-1]==str[i][j-1] && str[i-1][j]!=str[i][j])
                    {
                        if(seq[str[i-1][j]-'A']!=0)
                            seq[str[i][j]-'A']=seq[str[i-1][j]-'A']+1;
                        else if(seq[str[i][j]-'A']!=0)
                            seq[str[i-1][j]-'A']=seq[str[i][j]-'A']-1;
                    }
                }
            }
        }
    }
    for(i=0;i<26;i++)
    {
        printf("%d, ", seq[i]);
        if(seq[i]!=0)
            order[seq[i]]=i+'A';
    }
    len=strlen(order);
    for(i=0;i<len;i++)
        if(order[i]!='.')
            printf("%c", order[i]);
    printf("\n");
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
