//Accepted
//11565 - Simple Equations

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int x,y,z,A,B,C,t;
    bool sol;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &A,&B,&C);
        sol=false;
        for(x=-22; x<=22 && !sol; x++)
        {
            if(x*x<=C)
                for(y=-100;y<=100 && !sol;y++)
                {
                    if(y!=x && x*x + y*y <=C)
                        for(z=-100;z<=100&& !sol;z++)
                        {
                            if(z!=x && z!=y && x+y+z==A && x*y*z==B && x*x + y*y + z*z == C)
                            {
                                printf("%d %d %d\n", x, y, z);
                                sol=true;
                            }
                        }
                }
        }
        if(sol==false)
            printf("No solution.\n");
    }
    return 0;
}
