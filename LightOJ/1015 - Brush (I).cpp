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
int main()
{
    int t, n, amount, sum, cas;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d", &n);
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &amount);
            if(amount>0)
                sum+=amount;
        }
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
