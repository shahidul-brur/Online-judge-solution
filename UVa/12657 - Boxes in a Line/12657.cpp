#include <stdio.h>
int main()
{
    freopen("12657.txt", "r", stdin);
    int cas=1, n, m, i, box[100005], j, command, x, y, temp, sum, index[100005];
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        for(i=1;i<=n;i++)
            box[i]=i;
        for(i=1;i<=m;i++)
        {
            scanf("%d", &command);
            if(command!=4)
                scanf("%d %d", &x, &y);

            if(command==3)
            {
                temp=box[x];
                box[x]=box[y];
                box[y]=box[temp];
            }
            else if(command==4)
            {
                for(j=1;j<=n;j++)
                    box[j]=box[n-j+1];
            }
            else if(command==1)
            {
                box[x]=box[y]-1;
                for(j=box[x+1];j<box[y];j++)
                    box[j]--;
            }
            else if(command==2)
            {
                box[x]=box[y]+1;
                for(j=box[x+1];j<=box[y];j++)
                    box[j]--;
            }
        }
        sum=0;
        for(i=1;i<=n;i++)
            if(box[i]%2!=0)
                sum+=box[i];
        printf("Case %d: %d\n", cas, sum);
        cas++;
    }
    return 0;
}
