//Accepted

#include<stdio.h>
#include<string.h>
struct sub
{
    int team[1000];
    int coun;
};
int main()
{
    freopen("12667.txt","r",stdin);
    int p,t,s,time,id,i,j,k,last[15],last_id[105],pb,flag;
    struct sub problem[15];
    char ver[10],prob[5],p_id;
    scanf("%d %d %d",&p,&t,&s);
    for(i=0;i<13;i++)
        last[i]=-1;
    for(i=0;i<14;i++)
        problem[i].coun=0;
    for(i=1;i<=s;i++)
    {
        scanf("%d %d %s %s",&time,&id,&prob,&ver);
        if(ver[0]=='Y')
        {
            pb=prob[0]-'A';
            if(problem[pb].coun>0)
            {
                flag=1;
                for(k=0;k<problem[pb].coun;k++)
                    if(problem[pb].team[k]==id)
                    {
                        flag=0;
                        break;
                    }
                if(flag==1)
                {
                    last[pb]=time;
                    last_id[pb]=id;
                    problem[pb].team[problem[pb].coun]=id;
                    problem[pb].coun++;
                }
            }
            else if(problem[pb].coun==0)
            {
                last[pb]=time;
                last_id[pb]=id;
                problem[pb].team[problem[pb].coun]=id;
                problem[pb].coun++;
            }
        }
    }
    p_id='A';
    for(i=0;i<p;i++)
    {
        if(last[i]==-1)
            printf("%c - -\n",p_id);
        else
            printf("%c %d %d\n",p_id,last[i],last_id[i]);
        p_id++;
    }
    return 0;
}
