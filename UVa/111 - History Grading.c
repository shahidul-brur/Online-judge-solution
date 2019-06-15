// Accepted

#include <stdio.h>
#define maxi 1010
int visited[maxi][maxi], precal[maxi][maxi], n, num1[maxi], num2[maxi];
int lcslen(int i, int j)
{
    if(i>n || j>n)
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
    freopen("111.txt", "r", stdin);
    int i, j;
    scanf("%d", &n);
    int temp[maxi], tmp[maxi];
    for(i=1;i<=n;i++)
        scanf("%d", &temp[i]);
    for(i=1;i<=n;i++)
        num1[temp[i]]=i;
    while(scanf("%d", &tmp[1])!=EOF)
    {
        for(i=2;i<=n;i++)
            scanf("%d", &tmp[i]);
        for(i=1;i<=n;i++)
            num2[tmp[i]]=i;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                visited[i][j]=0;
        printf("%d\n", lcslen(1,1));
    }
    return 0;
}
