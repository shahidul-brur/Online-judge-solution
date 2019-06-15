#include <iostream>
#include <stdio.h>

using namespace std;
#define eps 1e-6
int main()
{
    //freopen("10114.txt", "r", stdin);
    int month, depr, i, j, m, monthSL, prev;
    double down, loan, price, dep[102], install;
    while(scanf("%d %lf %lf %d", &month, &down, &loan, &depr)!=EOF)
    {
        if(month<0)
            break;
        price=down+loan;
        prev=0;
        for(i=0;i<depr;i++)
        {
            scanf("%d", &monthSL);
            scanf("%lf", &dep[monthSL]);
            for(j=prev+1;j<monthSL;j++)
                dep[j]=dep[prev];
            prev=monthSL;
        }
        for(j=prev+1;j<month;j++)
                dep[j]=dep[prev];
        install=(double)loan/month;

        for(m=0;m<month;m++)
        {
            printf("%d %.3lf %.3lf\n", m, loan, price);
            loan-=install;
            price-=price*dep[m];
            if(loan-price<eps)
                break;
        }
        printf("%d %.3lf %.3lf = ", m, loan, price);
        printf("%d month", m+1);
        if(m>1)
            printf("s");
        printf("\n");
    }
    return 0;
}
