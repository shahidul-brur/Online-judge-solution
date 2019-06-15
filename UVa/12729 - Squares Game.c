#include<stdio.h>
int main()
{
    freopen("12729.txt", "r", stdin);
    int t, m, n,i,ana,total,sq,cut,bob;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        total=m*n;
        sq=m/2*n/2;
        cut=sq/2;
        ana=4*(sq-cut);
        bob=total-ana;

       if(ana>bob)
            printf("Case #%d: Ana\n",i);
        else if(ana<bob)
            printf("Case #%d: Bob\n",i);
        else if(ana==bob)
            printf("Case #%d: Draw\n",i);
    }
    return 0;
}
