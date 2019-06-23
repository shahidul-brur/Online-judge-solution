#include <stdio.h>
#include <string.h>
int main()
{
    int allow[7][7], i, j, k, visited[7][7], var1, var2, var3, var4, var5, var6, var7, var8, var9, var10;
    memset(allow, 0, sizeof(allow));
    memset(visited, 0, sizeof(visited));
    allow[1][2]=allow[1][3]=allow[1][5]=1;
    allow[2][1]=allow[2][3]=allow[2][5]=1;
    allow[3][2]=allow[3][1]=allow[3][4]=allow[3][5]=1;
    allow[4][3]=allow[4][5]=1;
    allow[5][1]=allow[5][2]=allow[5][3]=allow[5][4]=1;

    var1=1;
    for(var2=2;var2<=5;var2++)
    {
        memset(visited, 0, sizeof(visited));
        if(allow[var1][var2]==1 && visited[var1][var2]==0)
        {
            visited[var1][var2]=1;
            visited[var2][var1]=1;
            for(var3=1;var3<=5;var3++)
            {
                if(allow[var2][var3]==1 && visited[var2][var3]==0)
                {
                    visited[var2][var3]=1;
                    visited[var3][var2]=1;
                    for(var4=1;var4<=5;var4++)
                    {
                        if(allow[var3][var4]==1 && visited[var3][var4]==0)
                        {
                            visited[var3][var4]=1;
                            visited[var4][var3]=1;
                            for(var5=1;var5<=5;var5++)
                            {
                                if(allow[var4][var5]==1 && visited[var4][var5]==0)
                                {
                                    visited[var4][var5]=1;
                                    visited[var5][var4]=1;
                                    for(var6=1;var6<=5;var6++)
                                    {
                                        if(allow[var5][var6]==1 && visited[var5][var6]==0)
                                        {
                                            visited[var5][var6]=1;
                                            visited[var6][var5]=1;
                                            for(var7=1;var7<=5;var7++)
                                            {
                                                if(allow[var6][var7]==1 && visited[var6][var7]==0)
                                                {
                                                    visited[var6][var7]=1;
                                                    visited[var7][var6]=1;
                                                    for(var8=1;var8<=5;var8++)
                                                    {
                                                        if(allow[var7][var8]==1 && visited[var7][var8]==0)
                                                        {
                                                            visited[var7][var8]=1;
                                                            visited[var8][var7]=1;
                                                            for(var9=1;var9<=5;var9++)
                                                            {
                                                                if(allow[var8][var9]==1 && visited[var8][var9]==0)
                                                                {
                                                                    visited[var8][var9]=1;
                                                                    visited[var9][var8]=1;
                                                                    printf("#\n");
                                                                }
                                                                if(visited[1][2]==1 && visited[2][3]==1 && visited[3][4]==1 && visited[4][5]==1 && visited[5][1]==1 && visited[3][5]==1 && visited[1][3]==1 && visited[2][5]==1 )
                                                                    printf("%d%d%d%d%d%d%d%d%d\n", var1, var2, var3, var4, var5, var6, var7, var8, var9);
                                                            /*
                                                                for(i=1;i<=5;i++)
                                                                {
                                                                    printf("%d# ", i);
                                                                    for(j=1;j<=5;j++)
                                                                    {
                                                                        printf("%d ", visited[i][j]);
                                                                    }
                                                                    printf("\n");
                                                                }
                                                                printf("\n");
                                                            */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
