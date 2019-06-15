//Accepted

#include <stdio.h>
#include <string.h>
int visited[110][110], R, C;
char grid[110][110];
void visit(int row, int col)
{
    if(visited[row][col]==1)
        return;
    if(grid[row][col]=='*')
        return;
    if(row>=R || row<0)
        return;
    if(col>=C || col<0)
        return;
    if(grid[row][col]=='@')
    {
        visited[row][col]=1;
        visit(row-1, col);
        visit(row, col-1);
        visit(row+1, col);
        visit(row, col+1);
        visit(row-1, col-1);
        visit(row-1, col+1);
        visit(row+1, col-1);
        visit(row+1, col+1);
    }
}
int main()
{
    //freopen("572.txt", "r", stdin);
    int i, j, oil;
    char temp[5];
    while(scanf("%d %d", &R, &C)!=EOF)
    {
        if(R==0 && C==0)
            break;

        for(i=0;i<R;i++)
            scanf("%s", grid[i]);

        memset(visited, 0, sizeof(visited));

        oil=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(grid[i][j]=='@')
                {
                    if(visited[i][j]==0)
                    {
                        oil++;
                        visit(i, j);
                    }
                }
            }
        }
        printf("%d\n",oil);
    }
    return 0;
}
