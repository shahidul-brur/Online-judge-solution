/**********************************************************
Status:     Accepted
Problem:    https://www.codechef.com/SEPT15/problems/MSTEP
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
    /***** for faster input output ********/
       ios_base::sync_with_stdio(false);
    /***** *********************** ********/
    freopen("in.txt", "r", stdin);
    int test, N, i, j, R[250002], C[250002], mov, value;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &N);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                scanf("%d", &value);
                R[value]=i;
                C[value]=j;
            }
        }
        mov=0;
        for(i=1;i<N*N;i++)
        {
            mov+=abs(R[i]-R[i+1])+abs(C[i]-C[i+1]);
        }
        printf("%d\n", mov);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

