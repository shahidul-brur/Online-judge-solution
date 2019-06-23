//Accepted

#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
char first[105][35], second[105][35];
int f, s;
string sol;
int visited[105][105], precal[105][105];
int lcslen(int a, int b)
{
    if(a==f || b==s)
        return 0;
    if (visited[a][b]==1)
        return precal[a][b];

    int ans=0;
    if(strcmp(first[a],second[b])==0)
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
void printLCS(int i,int j)
{
    if(i==f || j==s){
        int L=sol.size();
        if(L>0)
        {
            sol.erase(L-1, 1);
            cout<<sol<<endl;
            sol.erase(0, L);
        }
        return;
    }
    if(strcmp(first[i], second[j])==0){
        sol+=first[i];
        sol+=' ';
        printLCS(i+1,j+1);
    }
    else
    {
        if(precal[i+1][j]>precal[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}
int main()
{
    //freopen("531.txt", "r", stdin);
    char temp[35];
    int len, i, j;
    while(scanf("%s",temp)!=EOF)
    {
        f=0;
        s=0;
        if(strcmp(temp, "#")!=0)
        {
            strcpy(first[f++], temp);
            while(scanf("%s",temp)!=EOF)
            {
                if(strcmp(temp, "#")==0)
                    break;
                strcpy(first[f++], temp);
            }
        }
        while(scanf("%s",temp)!=EOF)
        {
            if(strcmp(temp, "#")==0)
                break;
            strcpy(second[s++], temp);
        }
        for(i=0;i<=f;i++)
            for(j=0;j<=s;j++)
                visited[i][j]=0;
        for(i=0;i<=f;i++)
            for(j=0;j<=s;j++)
                precal[i][j]=0;
        len=lcslen(0,0);
        printLCS(0,0);
        len=sol.size();
    }
    return 0;
}
