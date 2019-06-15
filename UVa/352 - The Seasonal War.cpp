/**********************************************************
Status:     Accepted
Problem:    UVa 352
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 10 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int visited[110][110], N;
char grid[110][110];
void visit(int row, int col)
{
    if(visited[row][col]==1)
        return;
    if(grid[row][col]=='0')
        return;
    if(row>=N || row<0)
        return;
    if(col>=N || col<0)
        return;
    if(grid[row][col]=='1')
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
    //freopen("352.txt", "r", stdin);
    int cas=1, i, j, eagol;
    char temp[5];
    while(scanf("%d", &N)!=EOF)
    {
        for(i=0;i<N;i++)
            scanf("%s", grid[i]);

        memset(visited, 0, sizeof(visited));

        eagol=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(visited[i][j]==0)
                    {
                        eagol++;
                        visit(i, j);
                    }
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", cas, eagol);
        cas++;
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
