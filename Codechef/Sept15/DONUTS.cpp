/**********************************************************
Status:
Problem:    https://www.codechef.com/SEPT15/problems/DONUTS
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
    freopen("in.txt", "r", stdin);
    int test, N, M, A[20002], i, ans, rest;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &N, &M);
        for(i=0;i<M;i++)
            scanf("%d", &A[i]);
        sort(A, A+M);
        ans=M-1;
        rest=ans;
        for(i=0;i<M;i++)
        {
            if(A[i]<=rest)
            {
                ans--;
                rest-=(A[i]+1);
            }
            else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

