//Accepted

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int Q[16000002];

int main()
{
    //freopen("1152.txt", "r", stdin);
    int n, t, cas, i, j, p=0, A[4000], B[4000], C[4000], D[4000], val, cnt=0, u, l;
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d", &n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                Q[p]=C[i]+D[j];
                p++;
            }
        }
        sort(Q, Q+p);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                val=-(A[i]+B[j]);
                u=upper_bound(Q, Q+p, val)-&Q[0];
                l=lower_bound(Q, Q+p, val)-&Q[0];
                cnt+=u-l;
            }
        }
        if(cas>1)
            printf("\n");
        printf("%d\n", cnt);
        cnt=0;
        p=0;
    }
    return 0;
}

