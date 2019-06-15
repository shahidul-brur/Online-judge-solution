//Accepted

#include <string.h>
#include <stdio.h>
#define maxi 1010
char A[maxi], B[maxi];
int visited[maxi][maxi], precal[maxi][maxi];
int lcslen(int a, int b)
{
    if(A[a]=='\0' || B[b]=='\0')
        return 0;
    if (visited[a][b]==1)
        return precal[a][b];

    int ans=0;
    if(A[a]==B[b])
        ans = 1+lcslen(a+1, b+1);
    else
    {
        int val1=lcslen(a+1, b);
        int val2=lcslen(a, b+1);
        ans=val1 > val2 ? val1:val2;
    }
    visited[a][b]=1;
    precal[a][b]=ans;
    return precal[a][b];
}
int main()
{
    freopen("10405.txt", "r", stdin);
    while(gets(A))
    {
        gets(B);
        memset(visited, 0, sizeof(visited));
        printf("%d\n", lcslen(0, 0));
    }
    return 0;

}
