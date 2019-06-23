#include<stdio.h>
int main()
{
    int t, i, ax,ay,bx,by,cx,cy,dx,dy,area;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d %d %d", &ax,&ay,&bx,&by,&cx,&cy);
        dx=ax+cx-bx;
        dy=ay+cy-by;
        area=(ax*by+bx*cy+cx*dy+dx*ay-ay*bx-by*cx-cy*dx-dy*ax)/2;
        if(area<0) area=0-area;
        printf("Case %d: %d %d %d\n",i,dx,dy,area);
    }
    return 0;
}
