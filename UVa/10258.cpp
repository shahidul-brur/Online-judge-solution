//Accepted
#include <stdio.h>
#include <string.h>
struct
{
    int solved, problem[12], penalty[12], wrong[12], tP, sub;
}p[105];
int main()
{
    freopen("10258.txt", "r", stdin);
    int t, c, i, j, k, len, d, prob, time, rankP[105], tmp;
    char cn[100], temp[5], judge;
    scanf("%d", &t);
    getchar();
    gets(temp);
    for(c=1;c<=t;c++)
    {
        for(i=1;i<=100;i++)
        {
            p[i].solved=0;
            p[i].tP=0;
            p[i].sub=0;
            rankP[i]=i;
            for(j=1;j<=10;j++)
            {
                p[i].wrong[j]=0;
                p[i].penalty[j]=0;
                p[i].problem[j]=0;
            }
        }
        while(gets(cn))
        {
            len=strlen(cn);
            if(len==0)
                break;

            d=prob=time=0;

            for(i=0;cn[i]!=' ';i++)
                d=d*10 + cn[i]-'0';
            for(i=i+1;cn[i]!=' ';i++)
                prob=prob*10 + cn[i]-'0';
            for(i=i+1;cn[i]!=' ';i++)
                time=time*10 + cn[i]-'0';
            judge=cn[len-1];

            if(judge=='C')
            {
                if(p[d].problem[prob]==0)
                {
                    p[d].solved++;
                    p[d].penalty[prob]=time + p[d].wrong[prob]*20;
                    p[d].tP+=p[d].penalty[prob];
                    p[d].problem[prob]=1;
                }
            }
            else if(judge=='I')
            {
                p[d].wrong[prob]++;
            }
            p[d].sub=1;
        }
        for(i=1;i<=100;i++)
        {
            for(j=1;j<100;j++)
            {
                if(p[rankP[j+1]].solved>p[rankP[j]].solved)
                {
                    tmp=rankP[j];
                    rankP[j]=rankP[j+1];
                    rankP[j+1]=tmp;
                }
                else if(p[rankP[j+1]].solved==p[rankP[j]].solved)
                {
                    if(p[rankP[j+1]].tP<p[rankP[j]].tP)
                    {
                        tmp=rankP[j];
                        rankP[j]=rankP[j+1];
                        rankP[j+1]=tmp;
                    }
                }
            }
    }

        if(c>1)
            printf("\n");
        for(i=1;i<=100;i++)
        {
            if(p[rankP[i]].sub>0)
                printf("%d %d %d\n", rankP[i], p[rankP[i]].solved, p[rankP[i]].tP);
        }

    }
    return 0;
}
