//Accepted

#include <stdio.h>
#include <string.h>
struct puzzle
{
    int SL;
    char word[13];
}acros[101], down[101];

int main()
{
    //freopen("232.txt", "r", stdin);
    int r, c, cas=1, i, j, k, b, dw, cr, num, inc;
    char grid[12][12], buffer[13];
    while(scanf("%d", &r)!=EOF)
    {
        if(r==0)
            break;
        scanf("%d", &c);
        for(i=0;i<r;i++)
        {
            scanf("%s", grid[i]);
        }

        dw=cr=0;
        num=1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]!='*')
                {
                    inc=0;

                    if(j==0)
                        inc=1;
                    else if(grid[i][j-1]=='*')
                        inc=1;

                    if(inc==1)
                    {
                        acros[cr].SL=num;
                        for(k=j, b=0;grid[i][k]!='*' && k<c;k++)
                            buffer[b++]=grid[i][k];
                        buffer[b]='\0';
                        strcpy(acros[cr].word, buffer);
                        cr++;
                    }
                    if(i==0)
                        inc=2;
                    else if(grid[i-1][j]=='*')
                        inc=2;

                    if(inc==2)
                    {
                        down[dw].SL=num;
                        for(k=i, b=0;grid[k][j]!='*' && k<r;k++)
                            buffer[b++]=grid[k][j];
                        buffer[b]='\0';
                        strcpy(down[dw].word, buffer);
                        dw++;
                    }
                    if(inc>0)
                        num++;
                }
            }
        }
        if(cas>1)
            printf("\n");
        printf("puzzle #%d:\nAcross\n", cas);
        for(i=0;i<cr;i++)
        {
            if(acros[i].SL<10)
                printf("  ");
            else if(acros[i].SL<100)
                printf(" ");
            printf("%d.%s\n", acros[i].SL, acros[i].word);
        }

        printf("Down\n");
        for(i=0;i<dw;i++)
        {
            if(down[i].SL<10)
                printf("  ");
            else if(down[i].SL<100)
                printf(" ");
            printf("%d.%s\n", down[i].SL, down[i].word);
        }
        cas++;
    }
    return 0;
}
