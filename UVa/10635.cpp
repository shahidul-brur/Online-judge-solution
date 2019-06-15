#include <stdio.h>
#define maxi 62502
int p, q, num1[maxi], num2[maxi];
int lcslen(int i, int j)
{
    if(i>p || j>q)
        return 0;

    int ans;
    if(num1[i]==num2[j])
        ans=1+lcslen(i+1, j+1);
    else
    {
        int v1=lcslen(i, j+1);
        int v2=lcslen(i+1, j);
        if(v1>v2)
            ans=v1;
        else ans=v2;
    }
    return ans;
}
int main()
{
    freopen("10635.txt", "r", stdin);
    int i, j, t, n, cas;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d %d %d", &n, &p, &q);

        for(i=0;i<=p;i++)
            scanf("%d", &num1[i]);
        for(i=0;i<=q;i++)
            scanf("%d", &num2[i]);
        printf("Case %d: %d\n", cas, lcslen(0,0));
    }
    return 0;
}
