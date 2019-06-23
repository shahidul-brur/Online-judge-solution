//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11917.txt", "r", stdin);
    int t, cas, n, i, j, day[110], d, Y, time;
    char sub[110][25], hw[25];
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&sub[i]);
            scanf("%d",&day[i]);
        }
        scanf("%d",&d);
        scanf("%s", &hw);
        Y=0;
        for(i=0;i<n;i++)
        {
            if(strcmp(hw, sub[i])==0)
            {
                Y=1;
                time=day[i];
                break;
            }
        }
        if(Y==0 || time>d+5)
            printf("Case %d: Do your own homework!\n",cas);
        else if(time<=d)
            printf("Case %d: Yesss\n", cas);
        else if(time>d && time<=d+5)
            printf("Case %d: Late\n", cas);

    }
    return 0;
}
