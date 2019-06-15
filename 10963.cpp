//Accepted

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t, cas, colum, rowUp, rowDown, i, diff, Y;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        Y=1;
        scanf("%d", &colum);
        scanf("%d %d", &rowUp, &rowDown);
        diff=abs(rowUp-rowDown);
        for(i=1;i<colum;i++)
        {
            scanf("%d %d", &rowUp, &rowDown);
            if(abs(rowUp-rowDown)!=diff)
                Y=0;
        }
        if(cas>1)
            printf("\n");
        if(Y==1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
