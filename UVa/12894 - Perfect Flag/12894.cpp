//Accepted
#include <stdio.h>
int main()
{
    freopen("12894.txt", "r", stdin);
    int x0,y0,x1,y1,cx,cy,r,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d%d",&x0,&y0,&x1,&y1,&cx,&cy,&r);
        if(6*(x1-x0)==10*(y1-y0) && (x1-x0)==5*r && 20*(cx-x0)==9*(x1-x0) && (cy-y0)==(y1-cy))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
