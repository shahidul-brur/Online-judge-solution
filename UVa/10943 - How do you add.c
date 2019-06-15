#include<stdio.h>
#define mod 1000000
int used[102];
long long count(int n, int k, int now, int path)
{
    int i;
    if(n==now && k==path)
    {
        printf("     <#%d %d>\n", now, path);
        return 0;
    }
    if(path>k)
        return -1;
    long long way = 0;
    for(i=0;i<=n-now;i++)
    {
        if(used[i]==0 && now+i<=n && path<=k)
        {
            used[i] = 1;
            printf("  #%d\n", i);
            int find = count(n, k, now+i, path+1)%mod;
            if(find>-1)
                way++;
            used[i] = 0;
        }
    }
    return way;
}
int main()
{
    int n, k, i, j, cnt;
    while(scanf("%d %d",&n,&k)!=EOF){
        if(n==0 && k==0)
            break;
        memset(used, 0, sizeof(used));
        cnt = count(n, k, 0, 0);
        printf("%lld\n",cnt);
    }
    return 0;
}
