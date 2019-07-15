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
#define sqr(a) ((a)*(a))
int main()
{
    int t, len, i, yes;
    char A[15], B[15];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", &A);
        scanf("%s", &B);
        len=strlen(A);
        yes=1;
        for(i=0;i<len;i++)
        {
            if(A[i]==B[i] || (A[i]=='?' || B[i]=='?'));
            else
            {
                yes=0;
                break;
            }
        }
        if(yes==1)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

