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
    int n, num[100002], no[100002], taken[100002], i, j, have[100002];
    cin>>n;
    for(i=0;i<=n;i++)
    {
        taken[i]=0;
        have[i]=0;
    }
    for(i=0;i<n;i++)
    {
        cin>>num[i];
        have[num[i]]=1;
    }
    j=0;
    for(i=1;i<=n;i++)
    {
        if(have[i]==0)
            no[j++]=i;
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(i>0)
        printf(" ");
        if(num[i]<=n && taken[num[i]]==0)
        {
            printf("%d", num[i]);
            taken[num[i]]=1;
        }
        else printf("%d", no[j++]);
    }
    printf("\n");
    return 0;
}
/**********************************************************
About this problem:

************************************************************/