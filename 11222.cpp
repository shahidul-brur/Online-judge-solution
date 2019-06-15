//Accepted
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct solving
{
    int solved, uniq, sL[1005], uL[1005];

}person[4];
int compare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    //freopen("11222.txt", "r", stdin);
    int t, i, maxi, cas, j, cp1, cp2, key, *found1, *found2;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        for(i=1;i<=3;i++)
        {
            scanf("%d", &person[i].solved);
            for(j=0;j<person[i].solved;j++)
                scanf("%d", &person[i].sL[j]);
            sort(person[i].sL, person[i].sL+person[i].solved);
        }
        maxi=0;
        for(i=1;i<=3;i++)
        {
            cp1=i+1;
            if(cp1>3)
                cp1=1;
            cp2=cp1+1;
            if(cp2>3)
                cp2=1;
            person[i].uniq=0;
            for(j=0;j<person[i].solved;j++)
            {
                key=person[i].sL[j];
                found1=(int *)bsearch(&key, person[cp1].sL, person[cp1].solved, sizeof(int), compare);
                found2=(int *)bsearch(&key, person[cp2].sL, person[cp2].solved, sizeof(int), compare);
                if(found1==NULL && found2==NULL)
                    person[i].uL[person[i].uniq++]=person[i].sL[j];
            }
            if(person[i].uniq>maxi)
                maxi=person[i].uniq;
        }
        printf("Case #%d:\n",cas);
        for(i=1;i<=3;i++)
        {
            if(person[i].uniq==maxi)
            {
                printf("%d %d", i, person[i].uniq);
                for(j=0;j<person[i].uniq;j++)
                    printf(" %d",person[i].uL[j]);
                printf("\n");
            }
        }
    }
    return 0;
}
