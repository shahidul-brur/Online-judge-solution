//Accepted
#include<stdio.h>
#include<string.h>
struct list{
char contry[80];
};
int main()
{
    freopen("10420.txt", "r", stdin);
    int i,t,j,count;
    char tmp[80];
    struct list visit[2002];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",&visit[i].contry);
        gets(tmp);
    }
    for(i=1;i<=t;i++)
    {
        for(j=1;j<t;j++)
        {
            if(strcmp(visit[j].contry, visit[j+1].contry)>0)
            {
                strcpy(tmp, visit[j].contry);
                strcpy(visit[j].contry, visit[j+1].contry);
                strcpy(visit[j+1].contry, tmp);
            }
        }
    }
    for(i=1;i<=t;i++)
    {
        count=1;
        j=i+1;
        while(strcmp(visit[i].contry, visit[j].contry)==0)
        {
            count++;
            j++;
        }
        i=j-1;
        printf("%s %d\n",visit[i].contry,count);
    }
    return 0;
}
