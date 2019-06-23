//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("12583.txt", "r", stdin);
    int t, n, c, k, i, j, lp, len, cnt;
    char person[520];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d %s",&n,&k,&person);
        len=strlen(person);
        cnt=0;
        for(i=0;i<len;i++)
        {
            for(lp=1, j=i-1;lp<=k && j>=0;j--, lp++)
            {
                if(person[j]==person[i])
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",c,cnt);
    }
    return 0;
}
