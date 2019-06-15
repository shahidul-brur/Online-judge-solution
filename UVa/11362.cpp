#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10005
int main()
{
    //freopen("11362.txt", "r", stdin);
    int t, n, i, j, c, len, L1, L2, flag;
    char phone[M][15], tmp[15];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        int n, i;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%s", phone[i]);
        qsort(phone, n, 15, (int (*)(const void *, const void *)) strcmp);
        flag=1;
        for(i=0;i+1<n;i++)
        {
            if(strncmp(phone[i], phone[i+1], strlen(phone[i]))==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
