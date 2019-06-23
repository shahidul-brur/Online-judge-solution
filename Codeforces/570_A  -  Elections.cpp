/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
int main()
{
    //freopen("a.txt", "r", stdin);
    int n, m, i, j, vote[102][102], maxi, ans, selected[102], mx, a;
    scanf("%d %d", &n, &m);
    for(j=1;j<=n;j++)
        selected[j]=0;
    mx=-1;
    for(i=1;i<=m;i++)
    {
        maxi=-1;

        for(j=1;j<=n;j++)
        {
            scanf("%d", &vote[i][j]);
            if(vote[i][j]>maxi)
            {
                maxi=vote[i][j];
                ans=j;
            }
        }
        selected[ans]++;
        /*
        if(selected[ans]>mx)
        {
            mx=selected[ans];
            a=ans;
        }
        else if(selected[ans]==mx && ans<a)
        {
            mx=selected[ans];
            a=ans;
        }
        */
    }
    for(i=1;i<=n;i++)
    {
        if(selected[i]>mx)
        {
            mx=selected[i];
            a=i;
        }
    }
    printf("%d\n", a);
    return 0;
}
/**********************************************************
About this problem:

************************************************************/