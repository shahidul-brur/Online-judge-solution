/*Accepted*/

#include<stdio.h>
int main()
{
    freopen("11068.txt", "r", stdin);
    int a1,b1,c1,a2,b2,c2;
    float x,y;
    while(scanf("%d %d %d\n%d %d %d",&a1,&b1,&c1,&a2,&b2,&c2) && (a1!=0 || b1!=0 || c1!=0 || a2!=0 || b2!=0 || c2!=0))
          {
              if((a1*b2-a2*b1)==0) printf("No fixed point exists.\n");
            else
                {
                    x=(float)(c1*b2-c2*b1)/(a1*b2-a2*b1);
                    y=(float)(a1*c2-a2*c1)/(a1*b2-a2*b1);
                    printf("The fixed point is at %.2f %.2f.\n",x,y);
                }
          }
}
