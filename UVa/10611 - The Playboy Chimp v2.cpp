//Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("10611.txt", "r", stdin);
    int n,g[50005],q,h,i,j,s,t;
    g[0] = -1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&g[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&h);
        s = lower_bound(g, g+n, h) - g;
        t = upper_bound(g, g+n, h) - g;
        if(s>=n || g[s]>=h)
            s--;
        if(g[t]<=h)
            t++;
        if(s<0)
            printf("X ");
        else printf("%d ",g[s]);
        if(t>=n)
            printf("X\n");
        else printf("%d\n",g[t]);
    }
    return 0;
}
