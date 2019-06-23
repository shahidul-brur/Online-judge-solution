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
    long long int t, cas, a, b, c;
    scanf("%lld", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);

        if((a*a + b*b)==c*c || (b*b + c*c)==a*a || (c*c + a*a)==b*b)
            printf("Case %lld: yes\n", cas);
        else printf("Case %lld: no\n", cas);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
