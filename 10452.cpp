//Accepted

#include <stdio.h>

int main()
{
    freopen("10452.txt", "r", stdin);
    int r, t, c, p, i, row, ins, L, R;
    char grid[10][10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        for(i=0;i<r;i++)
            scanf("%s", grid[i]);
        for(i=0;i<c;i++)
        {
            if(grid[r-1][i]=='@')
            {
                row=r-1;
                p=i;
                break;
            }
        }
        ins=0;
        L=R=1;
        while(ins<=7)
        {
            if(ins>0)
                printf(" ");
            if(p<c-1 && R==1)
                if(grid[row][p+1]=='I'||grid[row][p+1]=='E'||grid[row][p+1]=='H'||grid[row][p+1]=='O'||grid[row][p+1]=='V'||grid[row][p+1]=='A')
                {
                    printf("right");
                    p=p+1;
                    L=0;
                    R=1;
                    ins++;
                    continue;
                }

            if(p>0 && L==1)
                if(grid[row][p-1]=='I'||grid[row][p-1]=='E'||grid[row][p-1]=='H'||grid[row][p-1]=='O'||grid[row][p-1]=='V'||grid[row][p-1]=='A')
                {
                    printf("left");
                    p=p-1;
                    R=0;
                    L=1;
                    ins++;
                    continue;
                }
            if(row>0 && (grid[row-1][p]=='I'||grid[row-1][p]=='E'||grid[row-1][p]=='H'||grid[row-1][p]=='O'||grid[row-1][p]=='V'||grid[row-1][p]=='A'))
                {
                        printf("forth");
                        row=row-1;
                        R=L=1;
                        ins++;
                        continue;
                }
            if(p<(c-1))
                if(grid[row][p+1]=='#')
                {
                    printf("right");
                    ins++;
                    break;
                }
            if(p>0)
                if(grid[row][p-1]=='#')
                {
                    printf("left");
                    ins++;
                    break;
                }
            if(row>0)
                if(grid[row-1][p]=='#')
                {
                    printf("forth");
                    ins++;
                    break;
                }

        }
        printf("\n");
    }

    return 0;
}
