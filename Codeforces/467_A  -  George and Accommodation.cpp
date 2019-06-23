#include<stdio.h>
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, a, b, ans;
    scanf("%d", &n);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &a, &b);
        if(b-a>=2)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}