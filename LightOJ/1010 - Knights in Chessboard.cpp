/**********************************************************
Status:     not submitted
Problem:    lightoj 1010
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 31 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int x[]={1, -1, 0, 0};
int y[]={0, 0, 1, -1};
int xMove[]={2, 2, -2, -2, -1, 1, -1, 1};
int yMove[]={-1, 1, -1, 1, 2, 2, -2, -2};
int row, col, board[202][202], visited[202][202];
bool valid(int r, int c)
{
    if(r<0 || r>=row || c<0 || c>=col)
        return false;
    if(visited[r][c]==1)
        return false;
    return true;
}
bool attacked(int r, int c)
{
    for(int i=0;i<8;i++)
    {
        int r1=r+xMove[i];
        int c1=c+yMove[i];
        if(valid(r1, c1))
        {
            if(board[r1][c1]==1)
                return true;
        }
    }
    return false;
}
void calculate(int r, int c)
{
    visited[r][c]=1;

    if(!attacked(r, c))
        board[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int r1=r+x[i];
        int c1=c+y[i];
        if(valid(r1, c1))
            calculate(r1, c1);
    }
}
int main()
{
    freopen("1010.txt", "r", stdin);
    int test, cas, ans;
    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>row>>col;
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
        calculate(0, 0);
        ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==1)
                    ans++;
            }
        }
        printf("Case %d: %d\n", cas, row*col/2+(row*col)%2);
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
