#include<stdio.h>
int main()
{
    int t, x, y, z, i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&x,&y,&z);
        if((x>y && x<z) || (x<y && x>z))
            printf("Case %d: %d\n",i,x);
        else if((y>x && y<z) || (y<x && y>z))
            printf("Case %d: %d\n",i,y);
        else if((z>y && z<x) || (z<y && z>x))
            printf("Case %d: %d\n",i,z);
    }
    return 0;
}
