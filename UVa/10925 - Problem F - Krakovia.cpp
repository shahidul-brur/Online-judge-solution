#include<stdio.h>
#include<math.h>
int main()
{
    freopen("10925.txt", "r", stdin);
    int i=1,j,n,f;
    double v,s,p;
    while(scanf("%d %d",&n,&f)==2)
    {
        if(n==0 && f==0)
            break;
        s=0;
        for(j=1;j<=n;j++)
        {
            scanf("%lf",&v);
            s+=v;
        }
        p=s/f;
        printf("Bill #%d costs %.0lf: each friend should pay %.0lf\n\n",i,s,floor(p));
        i++;
    }
    return 0;
}
