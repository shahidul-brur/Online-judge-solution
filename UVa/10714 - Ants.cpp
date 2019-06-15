#include<stdio.h>
#include<algorithm>
using namespace std;
int p[1000002];
int main()
{
    freopen("10714.txt", "r", stdin);
    int t,l,n,i,j,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&n);
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);
        sort(p, p+n);
            printf("%d %d\n",l-p[n-2],l-p[0]);
    }
    return 0;
}
