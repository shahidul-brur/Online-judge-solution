#include <stdio.h>
#include <string.h>
char board[205][205];
int visited[205][205], n;
int B(int r, int c)
{
    if(board[r][c]=='w')
        return 0;
    if(r>n || r<1 || c>n || c<1)
        return 0;
    if(r==n)
        return 1;
    return 0+B(r-1, c-1)+B(r-1, c)+B(r, c-1)+B(r, c+1)+B(r+1, c)+B(r+1, c+1);
}
int main()
{
    freopen("260.txt", "r", stdin);
    int i, j, b, w, cas=1;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=1;i<=n;i++)
            scanf("%s", board[i]);
        memset(visited, 0, sizeof(visited));
        b=w=0;
        for(i=1;i<=n;i++)
        {
            if(board[i][1]=='b')
                if(B(1,i)==1)
                {
                    b=1;
                    break;
                }
        }

        if(b==1)
            printf("%d B\n", cas);
        if(w==1)
            printf("%d W\n", cas);

        cas++;

    }
    return 0;
}
