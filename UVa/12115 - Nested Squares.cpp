/**********************************************************
Status:     Accepted
Problem:    UVa 12115
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
char str[100005];
int main()
{
    //freopen("e.txt", "r", stdin);
    int t, cas, Q, q, i, j, r1, c1, r2, c2, len, r, c, siz;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s %d", str, &Q);
        len=strlen(str);
        siz=2*len-1;
        for(j=len-2, i=len;i<siz;i++, j--)
        {
            str[i]=str[j];
        }
        str[siz]='\0';

        printf("Square %d:\n", cas);
        for(q=1;q<=Q;q++)
        {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            printf("Query %d:\n", q);
            for(i=r1;i<=r2;i++)
            {
                for(j=c1;j<=c2;j++)
                {
                    if(i<j)
                    {
                        if(j<=i-1+siz-(i-1)*2)
                            printf("%c", str[i-1]);
                        else printf("%c", str[j-1]);
                    }
                    else if(j<i)
                    {
                        if(i<=j-1+siz-(j-1)*2)
                            printf("%c", str[j-1]);
                        else printf("%c", str[i-1]);
                    }
                    else if(i==j)
                        printf("%c", str[i-1]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
