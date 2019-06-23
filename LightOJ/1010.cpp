#include <stdio.h>
int main()
{
    int test, row, col,cas;
    scanf("%d",&test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &row, &col);
        printf("Case %d: %d\n", cas, row*col/2+(row*col)%2);
    }
    return 0;
}
