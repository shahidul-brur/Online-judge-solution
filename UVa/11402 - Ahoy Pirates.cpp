#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("11402.txt", "r", stdin);
    int test, cas, query, q, Set, times, i, j, bucc, from, to;
    char pirates[1024003], temp[53], task[3];
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        pirates[0]='\0';
        cin>>Set;
        while(Set--)
        {
            cin>>times;
            scanf("%s", temp);
            for(i=1;i<=times;i++)
            {
                strcat(pirates, temp);
            }
        }
        cin>>query;
        q=1;

        printf("Case %d:\n", cas);
        while(query--)
        {
            scanf("%s %d %d", task, &from, &to);
            //printf("%s %d %d\n", task, from, to);
            if(task[0]=='F')
            {
                for(i=from;i<=to;i++)
                {
                    pirates[i]='1';
                }
            }

            else if(task[0]=='E')
            {
                for(i=from;i<=to;i++)
                {
                    pirates[i]='0';
                }
            }

            else if(task[0]=='I')
            {
                for(i=from;i<=to;i++)
                {
                    if(pirates[i]=='1')
                        pirates[i]='0';
                    else if(pirates[i]=='0')
                        pirates[i]='1';
                }
            }
            else if(task[0]=='S')
            {
                bucc=0;
                for(i=from;i<=to;i++)
                {
                    if(pirates[i]=='1')
                        bucc++;
                }
                printf("Q%d: %d\n", q, bucc);
                q++;
            }
        }
    }
    return 0;
}
