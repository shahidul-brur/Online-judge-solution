/**********************************************************
Status:     Accepted
Problem:    UVa 514 - Rails
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created:  - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    //freopen("892.txt", "r", stdin);
    char line[65];
    int hyp, h, i, j, len;
    while(gets(line))
    {
        len=strlen(line);
        if(len==1 && line[0]=='#')
            break;
        i=0;
        if(hyp==1)
        {
            for(i=0;i<len;i++)
            {
                if(line[i]==' ')
                    break;
                if((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z'))
                    printf("%c", line[i]);
            }
            printf("\n");
        }
        hyp=0;
        h=len;
        if(line[len-1]=='-')
        {
            hyp=1;
            for(h=len-1;h>=0 && line[h]!=' ';h--);
            h++;
        }
        for(;i<h;i++)
        {
            if((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') || line[i]==' ')
                printf("%c", line[i]);
        }
        printf("\n");
        if(hyp==1)
        {
            for(i=h;i<len;i++)
                if((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') || line[i]==' ')
                    printf("%c", line[i]);
        }
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
