#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct categori
{
    int model;
    int price[25];
}item[25];
int main()
{
    freopen("11450.txt", "r", stdin);
    int t, bg, sh,i,j,k,temp,sum,maxi;
    scanf("%d",&t);
    while(t--)
    {
        maxi=0;
        scanf("%d %d",&bg,&sh);
        for(i=0;i<sh;i++)
        {
            scanf("%d",&item[i].model);
            for(j=0;j<item[i].model;j++)
                scanf("%d",&item[i].price[j]);
            sort(item[i].price, item[i].price+item[i].model);
        }

        if(maxi==0)
            printf("no solution\n");
        else
            printf("%d\n",maxi);
    }
    return 0;
}
