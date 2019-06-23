#include<stdio.h>
struct board
{
    char cell[105];
};
int main()
{
    int n,i,j,flag,count;
    struct board row[105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&row[i].cell);

    }
    flag=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            count=0;
            if(j<n-1)
            {
                if(row[i].cell[j+1]=='o')
                    count++;
            }
             if(j>0)
            {
                if(row[i].cell[j-1]=='o')
                    count++;
            }
             if(i<n-1)
            {
                if(row[i+1].cell[j]=='o')
                    count++;
            }
             if(i>0)
            {
                if(row[i-1].cell[j]=='o')
                    count++;
            }
             if(count%2==1)
             {
                 flag=0;
                 break;
             }

        }
        if(flag==0)
            break;
    }
    if(flag==1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}