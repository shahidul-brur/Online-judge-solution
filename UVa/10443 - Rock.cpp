//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10443.txt", "r", stdin);
    int t, r, c,n,i,j,k,Case;
    char grid[110][110],after_war[110][110];
    scanf("%d",&t);
    for(Case=1;Case<=t;Case++)
    {
        scanf("%d %d %d",&r,&c,&n);
        for(i=0;i<r;i++)
            scanf("%s",&grid[i]);
        for(i=0;i<r;i++)
            strcpy(after_war[i],grid[i]);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                {
                    if(grid[j][k]=='R')
                    {
                        if(j>0)
                            if(grid[j-1][k]=='P')
                                after_war[j][k]='P';
                        if(j<r-1)
                            if(grid[j+1][k]=='P')
                                after_war[j][k]='P';
                        if(k>0)
                            if(grid[j][k-1]=='P')
                                after_war[j][k]='P';
                        if(k<c-1)
                            if(grid[j][k+1]=='P')
                                after_war[j][k]='P';
                    }
                    else if(grid[j][k]=='S')
                    {
                        if(j>0)
                            if(grid[j-1][k]=='R')
                                after_war[j][k]='R';
                        if(j<r-1)
                            if(grid[j+1][k]=='R')
                                after_war[j][k]='R';
                        if(k>0)
                            if(grid[j][k-1]=='R')
                                after_war[j][k]='R';
                        if(k<c-1)
                            if(grid[j][k+1]=='R')
                                after_war[j][k]='R';
                    }
                    else if(grid[j][k]=='P')
                    {
                        if(j>0)
                            if(grid[j-1][k]=='S')
                                after_war[j][k]='S';
                        if(j<r-1)
                            if(grid[j+1][k]=='S')
                                after_war[j][k]='S';
                        if(k>0)
                            if(grid[j][k-1]=='S')
                                after_war[j][k]='S';
                        if(k<c-1)
                            if(grid[j][k+1]=='S')
                                after_war[j][k]='S';
                    }
                }
            }
            for(j=0;j<r;j++)
                strcpy(grid[j],after_war[j]);
        }
        if(Case>1)
            printf("\n");
        for(j=0;j<r;j++)
            puts(after_war[j]);
    }
    return 0;
}
