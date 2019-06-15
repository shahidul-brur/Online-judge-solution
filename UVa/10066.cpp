//Accepted
#include <stdio.h>
#define maxi 110
int visited[maxi][maxi], precal[maxi][maxi], n1, n2, num1[maxi], num2[maxi];
int lcslen(int i, int j)
{
    if(i==n1 || j==n2)
        return 0;
    if(visited[i][j]==1)
        return precal[i][j];

    int ans;
    if(num1[i]==num2[j])
        ans=1+lcslen(i+1, j+1);
    else
    {
        int v1=lcslen(i, j+1);
        int v2=lcslen(i+1, j);
        if(v1>v2)
            ans=v1;
        else ans=v2;
    }
    visited[i][j]=1;
    precal[i][j]=ans;
    return precal[i][j];
}
int main()
{
    freopen("10066.txt", "r", stdin);
    int i, j, cas=1;
    while(scanf("%d %d", &n1, &n2)!=EOF)
    {
        if(n1==0 && n2==0)
            break;
        for(i=0;i<n1;i++)
            for(j=0;j<n2;j++)
                visited[i][j]=0;
        for(i=0;i<n1;i++)
            scanf("%d",&num1[i]);
        for(i=0;i<n2;i++)
            scanf("%d", &num2[i]);
        printf("Twin Towers #%d\n", cas);
        printf("Number of Tiles : %d\n\n", lcslen(0,0));
        cas++;
    }
    return 0;
}
