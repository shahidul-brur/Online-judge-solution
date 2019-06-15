#include <stdio.h>
int main()
{
    freopen("1016.txt", "r", stdin);
    int n, num[100000], cas=1, temp, i, j, cnt;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d", &num[i]);
        cnt=0;
        for(i=0;i<n;i++)
            for(j=0;j<n-1;j++)
                if(num[j]>num[j+1])
                    {
                        temp=num[j];
                        num[j]=num[j+1];
                        num[j+1]=temp;
                        cnt+=j+j+1;
                    }
        printf("Case %d: %d\n", cas, cnt);
        cas++;
    }
}
