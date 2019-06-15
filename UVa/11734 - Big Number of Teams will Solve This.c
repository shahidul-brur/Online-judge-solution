//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11734.txt", "r", stdin);
    int t,len1,len2,i,j,c,sp;
    char team[100],judge[100];
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++)
    {
        gets(team);
        len1=strlen(team);
        gets(judge);
        len2=strlen(judge);
        if(strcmp(team, judge)==0)
            printf("Case %d: Yes\n",c);
        else
        {
            for(i=j=0;team[i]!='\0';i++)
            {
                if(team[i]!=' ')
                    team[j++]=team[i];
            }
            team[j]='\0';
            if(strcmp(team,judge)==0)
                printf("Case %d: Output Format Error\n",c);
            else
                printf("Case %d: Wrong Answer\n",c);
        }
    }
    return 0;
}
