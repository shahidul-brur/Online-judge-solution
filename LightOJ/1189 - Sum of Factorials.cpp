/**********************************************************
Status:     Accepted
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
    unsigned long long int fact[22], i, n;
    int t, cas, j, take[22], space;
    fact[0]=fact[1]=1;
    for(i=2;i<=20;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lld", &n);
        memset(take, 0, sizeof(take));
        for(j=20;j>=0;j--)
        {
            if(fact[j]<=n)
            {
                take[j]=1;
                n-=fact[j];
            }
        }
        printf("Case %d: ", cas);
        if(n==0)
        {
            space=0;
            for(j=0;j<=20;j++)
            {
                if(take[j]==1)
                {
                    if(space==1)
                        printf("+");
                    printf("%d!", j);
                    space=1;
                }
            }
            printf("\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
