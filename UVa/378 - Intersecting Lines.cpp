/**********************************************************
Status:     Accepted
Problem:    UVa 514 - Rails
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 08 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-4
int main()
{
    freopen("378.txt", "r", stdin);
    int t, x1, y1, x2, y2, x3, y3, x4, y4, a1, b1, c1, a2, b2, c2;
    double x, y;
    scanf("%d", &t);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        a1=y1-y2;
        b1=x2-x1;
        c1=x1*y2 - x2*y1;
        a2=y3-y4;
        b2=x4-x3;
        c2=x3*y4 - x4*y3;

        if(a1*b2==a2*b1)
        {
            if(c1*b2==c2*b1 && c1*a2==c2*a1)
            {
                printf("LINE\n");
            }
            else
                printf("NONE\n");
        }
        else
        {
            x=(double)((double)(b1*c2-b2*c1)/(double)(a1*b2-a2*b1));
            y=(double)((double)(c1*a2-c2*a1)/(double)(a1*b2-a2*b1));
            printf("POINT %.2lf %.2lf\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
