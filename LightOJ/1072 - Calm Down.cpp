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
    int t, cas, n;
    double R, r;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lf %d", &R, &n);
        r=sin(pi/n)*R/(1+sin(pi/n));
        printf("Case %d: %lf\n", cas, r);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
