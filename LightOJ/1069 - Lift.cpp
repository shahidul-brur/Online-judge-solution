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
    int t, cas, lift, man, time;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d %d", &man, &lift);
        time=abs(man-lift) * 4 + 4*man + 2*5 + 3*3;
        printf("Case %d: %d\n", cas, time);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
