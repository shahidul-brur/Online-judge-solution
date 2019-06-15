//Accepted
#include<stdio.h>
struct matrix
{
    int col[15];
    int cl[15];
};
int main()
{
    freopen("11360.txt", "r", stdin);
    int t,n,c,comand,i,j,k,x,y,temp;
    char oper[12],str[20];
    struct matrix row[15];
    struct matrix rw[15];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",&str);
            for(j=0;j<n;j++)
            {
                row[i].col[j+1]=str[j]-'0';
            }
        }
        scanf("%d",&comand);
        while(comand--)
        {
            scanf("%s",&oper);
            if(oper[0]=='i')
            {
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        row[i].col[j]++;
                        if(row[i].col[j]>9)
                            row[i].col[j]-=10;
                        else if(row[i].col[j]<0)
                            row[i].col[j]+=10;
                    }
                }
            }
            else if(oper[0]=='d')
            {
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        row[i].col[j]--;
                        if(row[i].col[j]>9)
                            row[i].col[j]-=10;
                        else if(row[i].col[j]<0)
                            row[i].col[j]+=10;
                    }
                }
            }
            else if(oper[0]=='r')
            {
                scanf("%d %d",&x,&y);
                for(i=1;i<=n;i++)
                {
                    temp=row[x].col[i];
                    row[x].col[i]=row[y].col[i];
                    row[y].col[i]=temp;
                }
            }
            else if(oper[0]=='c')
            {
                scanf("%d %d",&x,&y);
                for(i=1;i<=n;i++)
                {
                    temp=row[i].col[x];
                    row[i].col[x]=row[i].col[y];
                    row[i].col[y]=temp;
                }
            }
            else if(oper[0]=='t')
            {
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        rw[i].cl[j]=row[i].col[j];
                    }
                }
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        row[i].col[j]=rw[j].cl[i];
                    }
                }
            }
        }
        printf("Case #%d\n",c);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(row[i].col[j]>9)
                    row[i].col[j]-=10;
                else if(row[i].col[j]<0)
                    row[i].col[j]+=10;
                printf("%d",row[i].col[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
