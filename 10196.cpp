//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("10196.txt", "r", stdin);
    int b, w, i, game=1, j, blank, kRow, kCol, KRow, KCol;
    char board[10][10], temp[10];
    while(scanf("%s", board[0])!=EOF)
    {
        blank=0;
        if(strcmp(board[0], "........")==0)
            blank++;
        for(i=1;i<8;i++)
        {
            scanf("%s", board[i]);
            if(strcmp(board[i], "........")==0)
                blank++;
        }
        if(blank==8)
            break;

        kRow=kCol=KRow=KCol=-1;
        b=w=0;

        // where the kings are ?
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]=='k')
                {
                    kRow=i;
                    kCol=j;
                }
                if(board[i][j]=='K')
                {
                    KRow=i;
                    KCol=j;
                }
                if(kRow>-1 && KRow>-1)
                    break;
            }
            if(kRow>-1 && KRow>-1)
                break;
        }
        // Pawn front black king
        if(board[kRow+1][kCol-1]=='P' || board[kRow+1][kCol+1]=='P')
        {
            b=1;
            goto print;
        }

        // pawn front white King
        if(board[KRow-1][KCol-1]=='p' || board[KRow-1][KCol+1]=='p')
        {
            w=1;
            goto print;
        }

        // knight front white King
        if(board[KRow+1][KCol-2]=='n'
           || board[KRow+1][KCol+2]=='n'
           || board[KRow-1][KCol-2]=='n'
           || board[KRow-1][KCol+2]=='n'
           || board[KRow+2][KCol-1]=='n'
           || board[KRow+2][KCol+1]=='n'
           || board[KRow-2][KCol-1]=='n'
           || board[KRow-2][KCol+1]=='n')
            {
                w=1;
                goto print;
            }

        // Knight front black king
        if(board[kRow+1][kCol-2]=='N'
           || board[kRow+1][kCol+2]=='N'
           || board[kRow-1][kCol-2]=='N'
           || board[kRow-1][kCol+2]=='N'
           || board[kRow+2][kCol-1]=='N'
           || board[kRow+2][kCol+1]=='N'
           || board[kRow-2][kCol-1]=='N'
           || board[kRow-2][kCol+1]=='N')
            {
                b=1;
                goto print;
            }

        // rook or queen left side of white King
        for(i=KCol-1;i>=0;i--)
        {
            if(board[KRow][i]=='r' || board[KRow][i]=='q')
            {
                w=1;
                goto print;
            }
            if(board[KRow][i]!='.')
                break;
        }

        // rook or queen right side of white King
        for(i=KCol+1;i<8;i++)
        {
            if(board[KRow][i]=='r' || board[KRow][i]=='q')
            {
                w=1;
                goto print;
            }
            if(board[KRow][i]!='.')
                break;
        }

        // Rook or Queen left side of black king
        for(i=kCol-1;i>=0;i--)
        {
            if(board[kRow][i]=='R' || board[kRow][i]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[kRow][i]!='.')
                break;
        }

        // Rook or Queen right side of black king
        for(i=kCol+1;i<8;i++)
        {
            if(board[kRow][i]=='R' || board[kRow][i]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[kRow][i]!='.')
                break;
        }

        // rook or queen up side of white King
        for(i=KRow-1;i>=0;i--)
        {
            if(board[i][KCol]=='r' || board[i][KCol]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][KCol]!='.')
                break;
        }

        // rook or queen below side of white King
        for(i=KRow+1;i<8;i++)
        {
            if(board[i][KCol]=='r' || board[i][KCol]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][KCol]!='.')
                break;
        }

        // Rook or Queen up side of black king
        for(i=kRow-1;i>=0;i--)
        {
            if(board[i][kCol]=='R' || board[i][kCol]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][kCol]!='.')
                break;
        }

        // Rook or Queen below side of black king
        for(i=kRow+1;i<8;i++)
        {
            if(board[i][kCol]=='R' || board[i][kCol]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][kCol]!='.')
                break;
        }

        // bishop or queen upper left diagonal of white King
        for(i=KRow-1, j=KCol-1;i>=0 && j>=0;i--, j--)
        {
            if(board[i][j]=='b' || board[i][j]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

      // bishop or queen upper right diagonal of white King
        for(i=KRow-1, j=KCol+1;i>=0 && j<8;i--, j++)
        {
            if(board[i][j]=='b' || board[i][j]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

        // bishop or queen lower left diagonal of white King
        for(i=KRow+1, j=KCol-1;i<8 && j>=0;i++, j--)
        {
            if(board[i][j]=='b' || board[i][j]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

      // bishop or queen lower right diagonal of white King
        for(i=KRow+1, j=KCol+1;i<8 && j<8;i++, j++)
        {
            if(board[i][j]=='b' || board[i][j]=='q')
            {
                w=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

        // bishop or queen upper left diagonal of black King
        for(i=kRow-1, j=kCol-1;i>=0 && j>=0;i--, j--)
        {
            if(board[i][j]=='B' || board[i][j]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

      // bishop or queen upper right diagonal of white King
        for(i=kRow-1, j=kCol+1;i>=0 && j<8;i--, j++)
        {
            if(board[i][j]=='B' || board[i][j]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

        // bishop or queen lower left diagonal of white King
        for(i=kRow+1, j=kCol-1;i<8 && j>=0;i++, j--)
        {
            if(board[i][j]=='B' || board[i][j]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

      // bishop or queen lower right diagonal of black King
        for(i=kRow+1, j=kCol+1;i<8 && j<8;i++, j++)
        {
            if(board[i][j]=='B' || board[i][j]=='Q')
            {
                b=1;
                goto print;
            }
            if(board[i][j]!='.')
                break;
        }

        print:
            if(w==1)
                printf("Game #%d: white king is in check.\n", game);
            else if(b==1)
                printf("Game #%d: black king is in check.\n", game);
            else if(b==0 && w==0)
                printf("Game #%d: no king is in check.\n", game);

        game++;
    }
    return 0;
}
