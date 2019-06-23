//Accepted

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int visited[1000][1000], precal[1000][1000], L, A[1000], B[1000], n;
int lcsLen(int i, int j)
{
    if(i==n || j==n)
        return 0;
    if(visited[i][j]==1)
        return precal[i][j];

    int ans = 0;
    if(A[i] == B[j])
        ans = 1+lcsLen(i+1, j+1);
    else
    {
        int v1 = lcsLen(i+1, j);
        int v2 = lcsLen(i, j+1);
        ans = v1 > v2 ? v1:v2;
    }
    visited[i][j]=1;
    precal[i][j] = ans;
    return precal[i][j];
}
void printLCS(int i, int j)
{
    if(i==n || j==n)
        return;
    if(A[i] == B [j])
    {
        printf("%d\n", A[i]);
        printLCS(i+1, j+1);
    }
    else
    {
        if(precal[i+1][j]>precal[i][j+1])
            printLCS(i+1, j);
        else
            printLCS(i, j+1);
    }
}
int main()
{
    freopen("497.txt", "r", stdin);
    char str[20];
    int t, c, i;
    scanf("%d", &t);
    getchar();
    gets(str);
    for(c=1;c<=t;c++)
    {
        i=0;
        while(gets(str))
        {
            if(str[0]=='\0')
                break;
            A[i] = atoi(str);
            B[i] = A[i];
            i++;
        }
        n=i;
        sort(A, A+n);
        memset(visited, 0, sizeof(visited));
        if(c>1)
            printf("\n");
        printf("Max hits: %d\n", lcsLen(0, 0));
        printLCS(0, 0);
    }
    return 0;
}
