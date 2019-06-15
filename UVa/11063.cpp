//Accepted
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("11063.txt", "r", stdin);
    int n, i, c, j, b2, cas=1, num[150], sum[10010];
    num[0]=0;
    while(scanf("%d",&n)!=EOF)
    {
        b2=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]<1)
                b2=0;
            else if(num[i]<=num[i-1])
                b2=0;
        }
        if(b2==1)
        {
            for(i=1,c=1;i<=n;i++)
            {
                for(j=i;j<=n;j++)
                {
                    sum[c++]=num[i]+num[j];
                }
            }
            c--;
            sort(sum+1, sum+c);
            for(i=1;i<=c-1;i++)
            {
                for(j=i+1;j<=c;j++)
                {
                    if(sum[j]==sum[i])
                    {
                        b2=0;
                        break;
                    }
                    if(b2==0)
                        break;
                }
            }
        }
        if(b2==1)
            printf("Case #%d: It is a B2-Sequence.\n\n",cas);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",cas);
        cas++;
    }
    return 0;
}
