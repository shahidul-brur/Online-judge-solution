//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11661.txt", "r", stdin);
    int L, mini, preD, preR, i;
    char str[2000001];
    while(scanf("%d", &L)!=EOF)
    {
        if(L==0)
            break;
        mini=2000009;
        preD=-1;
        preR=-1;
        scanf("%s", str);
        for(i=0;i<L;i++)
        {
            if(str[i]=='Z')
            {
                mini=0;
                break;
            }
            if(str[i]=='R')
            {
                preR=i;
                if(preD!=-1)
                {
                    if((preR-preD)<mini)
                        mini=preR-preD;
                }
            }
            if(str[i]=='D')
            {
                preD=i;
                if(preR!=-1)
                {
                    if((preD-preR)<mini)
                        mini=preD-preR;
                }
            }
        }
        printf("%d\n", mini);
    }
    return 0;
}
