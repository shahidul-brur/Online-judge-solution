//Accepted

#include <stdio.h>
#include <string.h>

int main()
{
    freopen("10284.txt", "r", stdin);
    int safe[20][20], i, j, len, k, m, cnt;
    char str[80], chess[20][20];
    while(scanf("%s", str)!=EOF)
    {
        len=strlen(str);
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                safe[i][j]=1;
                chess[i][j]='.';
            }
            chess[i][j]='\0';
        }
        i=j=0;
        for(k=0;k<len;k++)
        {
            if(str[k]>='1' && str[k]<='8')
                j+=str[k]-'0';
            else if(str[k]=='/')
            {
                i++;
                j=0;
            }
            else
            {
                chess[i][j++]=str[k];
            }
        }

        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(chess[i][j]!='.')
                    safe[i][j]=0;
                if(chess[i][j]=='p')
                {
                    safe[i+1][j-1]=0;
                    safe[i+1][j+1]=0;
                }
                if(chess[i][j]=='P')
                {
                    safe[i-1][j-1]=0;
                    safe[i-1][j+1]=0;
                }

                if(chess[i][j]=='N' || chess[i][j]=='n')
                {
                    safe[i-1][j-2]=0;
                    safe[i-1][j+2]=0;
                    safe[i+1][j-2]=0;
                    safe[i+1][j+2]=0;
                    safe[i-2][j-1]=0;
                    safe[i-2][j+1]=0;
                    safe[i+2][j-1]=0;
                    safe[i+2][j+1]=0;
                }

                if(chess[i][j]=='k' || chess[i][j]=='K')
                {
                    safe[i-1][j-1]=0;
                    safe[i-1][j+1]=0;
                    safe[i-1][j]=0;
                    safe[i+1][j-1]=0;
                    safe[i+1][j+1]=0;
                    safe[i+1][j]=0;
                    safe[i][j-1]=0;
                    safe[i][j+1]=0;
                }


                if(chess[i][j]=='B' || chess[i][j]=='b' || chess[i][j]=='q' || chess[i][j]=='Q')
                {
                    for(k=i-1, m=j-1;k>=0 && m>=0;k--, m--)
                    {
                        if(chess[k][m]=='.')
                            safe[k][m]=0;
                        else break;
                    }

                    for(k=i-1, m=j+1;k>=0 && m<8;k--, m++)
                    {
                        if(chess[k][m]=='.')
                            safe[k][m]=0;
                        else break;
                    }

                    for(k=i+1, m=j-1;k<8 && m>=0;k++, m--)
                    {
                        if(chess[k][m]=='.')
                            safe[k][m]=0;
                        else break;
                    }

                    for(k=i+1, m=j+1;k<8 && m<8;k++, m++)
                    {
                        if(chess[k][m]=='.')
                            safe[k][m]=0;
                        else break;
                    }

                }

                if(chess[i][j]=='R' || chess[i][j]=='r' || chess[i][j]=='q' || chess[i][j]=='Q')
                {
                    for(k=i-1, m=j;k>=0;k--)
                    {
                        if(chess[k][m]=='.')
                        {
                            safe[k][m]=0;
                        }
                        else break;
                    }

                    for(k=i+1, m=j;k<8;k++)
                    {
                        if(chess[k][m]=='.')
                        {
                            safe[k][m]=0;
                        }
                        else break;
                    }

                    for(k=i, m=j-1;m>=0;m--)
                    {
                        if(chess[k][m]=='.')
                        {
                            safe[k][m]=0;
                        }
                        else break;
                    }

                    for(k=i, m=j+1;m<8;m++)
                    {
                        if(chess[k][m]=='.')
                            safe[k][m]=0;
                        else
                            break;
                    }
                }
            }
        }

        cnt=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(safe[i][j]==1)
                    cnt++;
            }
        }
        printf("%d\n", cnt);

    }
    return 0;
}
