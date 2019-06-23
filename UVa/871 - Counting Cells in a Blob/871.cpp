//Accepted

#include <stdio.h>
#include <string.h>
int visited[30][30], R, C;
char grid[30][30];
int countCell(int row, int col)
{
    if(visited[row][col]==1)
        return 0;
    if(grid[row][col]=='0')
        return 0;
    if(row>=R || row<0)
        return 0;
    if(col>=C || col<0)
        return 0;
    if(grid[row][col]=='1')
    {
        visited[row][col]=1;
        return 1+countCell(row-1, col)+countCell(row, col-1)+countCell(row+1, col)+countCell(row, col+1)+countCell(row-1, col-1)+countCell(row-1, col+1)+countCell(row+1, col-1)+countCell(row+1, col+1);
    }
}

int main()
{
    //freopen("871.txt", "r", stdin);
    int t, i, j, maxi, len, cnt, cas;
    char temp[5];
    scanf("%d", &t);
    getchar();
    gets(temp);
    for(cas=1;cas<=t;cas++)
    {
        i=0;
        while(gets(grid[i]))
        {
            len=strlen(grid[i]);
            if(len==0)
                break;
            i++;
        }
        R=i;
        C=strlen(grid[0]);
        maxi=0;
        memset(visited, 0, sizeof(visited));
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                cnt=countCell(i, j);
                if(cnt>maxi)
                    maxi=cnt;
            }
        }
        if(cas>1)
            printf("\n");
        printf("%d\n",maxi);
    }
    return 0;
}
