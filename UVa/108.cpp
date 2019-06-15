//Accepted

#include <iostream>
#include <cstdio>
using namespace std;
int matrix[102][102], N, rowSum[102][102];
int sumUp(int r, int c, int row, int col)
{
    int sum=0, i, j;
    for(i=r;i<r+row;i++)
    {
        sum+=rowSum[i][c+col-1]-rowSum[i][c-1];
    }
    return (sum);
}
int main()
{
    //freopen("108.txt", "r", stdin);
    int i, j, k, l, maxi, sum;
    while(scanf("%d", &N)!=EOF)
    {
        for(i=1;i<=N;i++)
        {
            rowSum[i][0]=0;
            for(j=1;j<=N;j++)
            {
                scanf("%d", &matrix[i][j]);
                rowSum[i][j]=rowSum[i][j-1]+matrix[i][j];
            }
        }
        maxi=-1111111111;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                for(k=1;k<=(N+1-i);k++)
                {
                    for(l=1;l<=(N+1-j);l++)
                    {
                        sum=sumUp(i, j, k, l);
                        if(sum>maxi)
                            maxi=sum;
                    }
                }
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
