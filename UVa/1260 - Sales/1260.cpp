//Accepted
#include <stdio.h>

int main()
{
    int t, n, a[1005],i,j,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i>0)
            {
                for(j=0;j<i;j++)
                {
                    if(a[j]<=a[i])
                        cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
