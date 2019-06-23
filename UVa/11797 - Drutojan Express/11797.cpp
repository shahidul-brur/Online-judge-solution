#include <bits/stdc++.h>
using namespace std;
struct lst
{
    int listLen, time;
    queue<int> serial;
    char name[5];
    char listname[25][5];
}SL[7];
int main()
{
    freopen("11797.txt", "r", stdin);
    int start, t, c, M, N, i, k, j, tmp;
    char first[5];
    strcpy(SL[1].name, "Ja");
    strcpy(SL[2].name, "Sam");
    strcpy(SL[3].name, "Sha");
    strcpy(SL[4].name, "Sid");
    strcpy(SL[5].name, "Tan");

    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d %s", &M, &N, first);

        for(i=1;i<=5;i++)
        {
            if(strcmp(first, SL[i].name)==0)
            {
                start=i;
                break;
            }
        }

        for(i=1;i<=5;i++)
            SL[i].time=0;

        for(i=1;i<=5;i++)
        {
            scanf("%d",&SL[i].listLen);
            for(j=1;j<=SL[i].listLen;j++)
            {
                scanf("%s",SL[i].listname[j]);
                for(k=1;k<=5;k++)
                {
                    if(strcmp(SL[i].listname[j], SL[k].name)==0)
                    {
                        SL[i].serial.push(k);
                        break;
                    }
                }
            }
        }
        i=start;
        while(N>0)
        {
            if(N<=M)
            {
                SL[i].time+=N;
                N=0;
            }
            else
            {
                SL[i].time+=M;
                N-=(M+2);
                start=SL[i].serial.front();
                SL[i].serial.pop();
                SL[i].serial.push(start);
                i=start;
            }
        }
        printf("Case %d:\n",c);
        for(i=1;i<=5;i++)
            printf("%s %d\n",SL[i].name, SL[i].time);
        
        for(i=1;i<=5;i++)
        {
            while(!SL[i].serial.empty())
                SL[i].serial.pop();
        }
    }
    return 0;
}
