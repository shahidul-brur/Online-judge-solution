#include <bits/stdc++.h>
int main()
{
    int n, k, cnt, i, score[55];
    scanf("%d %d", &n, &k);
    for(i=1;i<=n;i++)
        scanf("%d", &score[i]);
        cnt=0;
    for(i=1;i<=n;i++)
        if(score[i]>=score[k] && score[i]>0)
        cnt++;
    printf("%d\n", cnt);
    return 0;
}