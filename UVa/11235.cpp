#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11235.txt", "r", stdin);
    int n, q, i, j, maxi, cnt, value[100003], from, to, f[100003], k;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%d", &q);
        for(i=1, cnt=1;i<=n;i++)
        {
            scanf("%d", &value[i]);
            if(i>1)
            {
                if(value[i]==value[i-1])
                    cnt++;
                else
                {
                    for(j=i-1;value[j]==value[i-1];j--)
                        f[j]=cnt;
                    cnt=1;
                }
            }
        }
        for(j=i-1;value[j]==value[i-1];j--)
            f[j]=cnt;

        for(i=1;i<=q;i++)
        {
            scanf("%d %d", &from, &to);
            maxi=1;
            for(j=from;j<=to;j++)
            {
                if(j==from)
                {
                    for(k=from-1, cnt=0;from>=1 && value[k]==value[from];k--)
                        cnt++;
                    for(k=to+1;k<=n && value[k]==value[from];k++)
                        cnt++;
                    if(f[from]-cnt >maxi)
                        maxi=f[from]-cnt;
                    for(k=from+1;value[k]==value[from];k++)
                        j++;
                }
                else if(j==to)
                {
                    for(k=from-1, cnt=0;from>=1 && value[k]==value[to];k--)
                        cnt++;
                    for(k=to+1;k<=n && value[k]==value[to];k++)
                        cnt++;
                    if(f[to]-cnt > maxi)
                        maxi=f[to]-cnt;
                }
                else if(j!=from && j!=to)
                {
                    if(value[j]==value[to])
                        j=to-1;
                    else if(f[j]>maxi)
                        maxi=f[j];
                }
            }
            printf("%d\n", maxi);
        }
    }
    return 0;
}
