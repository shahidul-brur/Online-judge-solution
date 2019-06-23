#include <bits/stdc++.h>
int x[]={0, 0, 1, 1};
int y[]={0, 1, 0, 1};
using namespace std;
int main()
{
    int r, c, cnt,i, j, k, l, a, b, F,A, C, E;
    char grid[52][52];
    scanf("%d %d", &r, &c);
    for(i=0;i<r;i++)
        scanf("%s", grid[i]);
    for(i=0, cnt=0;i<r-1;i++)
    {
        for(j=0;j<c-1;j++)
        {
            F=A=C=E=0;
            for(k=0;k<4;k++)
            {
                a=i+x[k];
                b=j+y[k];
                if(grid[a][b]=='f')
                    F=1;
                else if(grid[a][b]=='a')
                    A=1;
                else if(grid[a][b]=='c')
                    C=1;
                else if(grid[a][b]=='e')
                    E=1;

            }
            if(F+A+C+E==4)
                cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}