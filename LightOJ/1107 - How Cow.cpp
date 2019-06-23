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
    freopen("in.txt", "r", stdin);
    int t, cas, cow, x, y, x1, x2, y1, y2;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &cow);
        printf("Case %d:\n", cas);
        while(cow--)
        {
            scanf("%d %d", &x, &y);
            if(x>x1 && x<x2 &&y>y1 && y<y2)
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
