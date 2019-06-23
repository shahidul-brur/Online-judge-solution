//Accepted
#include <stdio.h>

int main()
{
    freopen("12750.txt", "r", stdin);
    char p[510];
    int t, n,c,i,cnt,unwin;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        cnt=unwin=0;
        for(i=0;i<n;i++)
        {
            scanf("\n%c",&p[i]);
        }
        p[i]='\0';
        for(i=0;i<n;i++)
        {
            cnt++;
            if(p[i]=='L' || p[i]=='D')
                unwin++;
            else if(p[i]=='W')
                unwin=0;
            if(unwin==3)
                break;

        }
        if(cnt==n && unwin<3)
            printf("Case %d: Yay! Mighty Rafa persists!\n",c);
        else
            printf("Case %d: %d\n",c,cnt);
    }
    return 0;
}
