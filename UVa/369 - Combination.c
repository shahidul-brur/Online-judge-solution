//Accepted

#include<stdio.h>
int main()
{
    long pas[110][110];
    int i,j,n,r;
    pas[0][0]=pas[1][0]=pas[1][1]=1;
    for(i=2;i<=100;i++)
    {
        pas[i][0]=1;
        for(j=1;j<i;j++)
        {
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
        pas[i][j]=1;
    }
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        if(n==0&&r==0)
            break;
        printf("%d things taken %d at a time is %ld exactly.\n",n,r,pas[n][r]);
    }
    return 0;
}
