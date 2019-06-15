//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("824.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int x, y, d, px, py, dir[10], sign, p, s;
    while(scanf("%d", &x)!=EOF)
    {
        if(x==-1)
            break;
        scanf("%d %d", &y, &d);

        for(int i=0;i<8;i++)
            dir[i]=1;

        for(int i=1;i<=8;i++)
        {
            scanf("%d %d %d", &px, &py, &sign);
            if(sign==0)
            {
                if(px==x && py==y+1)
                    p=0;
                else if(px==x-1 && py==y+1)
                    p=1;
                else if(px==x-1 && py==y)
                    p=2;
                else if(px==x-1 && py==y-1)
                    p=3;
                else if(px==x && py==y-1)
                    p=4;
                else if(px==x+1 && py==y-1)
                    p=5;
                else if(px==x+1 && py==y)
                    p=6;
                else if(px==x+1 && py==y+1)
                    p=7;

                dir[p]=0;
            }
        }

        for(int i=1, j=(d+8-2);i<=8;i++, j++)
        {
            if(dir[j%8]==1)
            {
                printf("%d\n", j%8);
                break;
            }
        }
    }
    return 0;
}
