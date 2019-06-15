/**********************************************************
Status:     Accepted
Problem:    UVa 12085
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on: 04-08-2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    //freopen("b.txt", "r", stdin);
    //freopen("bout.txt", "w", stdout);
    int n, cas=1, i, j, len, prev, now, same;
    char num[15], start[15], pre[15];
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        printf("Case %d:\n", cas++);
        scanf("%s", num);
        len=strlen(num);
        strcpy(start, num);
        prev=atoi(num);
        same=0;
        for(i=1;i<n;i++)
        {
            scanf("%s", num);

            now=atoi(num);

            //printf("  %d %d\n", now, prev);

            if((now-prev)==1)
            {
                same=1;
                //printf("   #%s %s\n", num, )
            }
            else
            {
               if(same==1)
                {
                    printf("%s", start);
                    for(j=0;j<len && pre[j]==start[j];j++);

                    printf("-");
                    for(;j<len;j++)
                        printf("%c", pre[j]);
                    printf("\n");
                }
                else printf("%s\n", start);
                same=0;
                strcpy(start, num);
            }
            strcpy(pre, num);
            prev=now;
        }
        if(same==1)
        {
            printf("%s", start);
            for(j=0;j<len && pre[j]==start[j];j++);

            printf("-");
            for(;j<len;j++)
                printf("%c", pre[j]);
            printf("\n");
        }
        else printf("%s\n", start);
        printf("\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
