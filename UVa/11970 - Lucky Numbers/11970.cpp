//Accepted

#include <stdio.h>
#include <math.h>
int main()
{
    freopen("11970.txt", "r", stdin);
    int n, i, t, cas, lucky[5000], L, r, root, x, square[31255];
    for(i=1;i<=31252;i++)
        square[i]=i*i;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(i=1, L=1;i<=31252;i++)
        {
            if(square[i]>=n)
                break;
            x=n-square[i];
            r=sqrt(square[i]);
            if(x%r==0)
                lucky[L++]=x;

        }
        printf("Case %d:",cas);
        for(i=L-1;i>0;i--)
            printf(" %d",lucky[i]);
        printf("\n");
    }
    return 0;
}
