//Accepted
#include <math.h>
#include <stdio.h>
int main()
{
    freopen("12816.txt", "r", stdin);
    int n, x[110], y[110], i, j, k, cnt, m;
    double ab, bc, ca;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for(i=1;i<=n;i++)
            scanf("%d %d",&x[i], &y[i]);
        for(i=1;i<=(n-2);i++)
        {
            for(j=i+1;j<=(n-1);j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    ab=sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
                    bc=sqrt((x[j] - x[k])*(x[j] - x[k]) + (y[j] - y[k])*(y[j] - y[k]));
                    ca=sqrt((x[k] - x[i])*(x[k] - x[i]) + (y[k] - y[i])*(y[k] - y[i]));
                    m=0;
                    if(fabs(ab+bc-ca)>0.000001 && fabs(bc+ca-ab)>0.000001 && fabs(ab+ca-bc)>0.000001)
                    {
                        if(fabs(ab-bc)<0.000001)
                            m++;
                        if(fabs(bc-ca)<0.000001)
                            m++;
                        if(fabs(ca-ab)<0.000001)
                            m++;
                        if(m==1)
                            cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
