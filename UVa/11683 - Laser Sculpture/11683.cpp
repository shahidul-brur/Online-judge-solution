//Accepted

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    freopen("11683.txt", "r", stdin);
    int H, L, h, i, j, cnt, struc[10002];
    while(scanf("%d",&H)!=EOF)
    {
        if(H==0)
            break;
        scanf("%d", &L);
        for(i=0;i<L;i++)
        {
            scanf("%d",&struc[i]);
        }
        //sort(struc, struc+L);
        cnt=H-struc[L-1];
        for(j=L-2;j>=0;j--)
        {
            if(struc[j]<struc[j+1])
                cnt=cnt+abs((H-struc[j])-(H-struc[j+1]));
        }
        printf("%d\n",cnt);
    }
    return 0;
}
