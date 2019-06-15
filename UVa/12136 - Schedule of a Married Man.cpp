#include<stdio.h>
int main()
{
    int N, wsh, wsm, weh, wem, msh, msm, meh, mem, cas;
    int ws, we, ms, me;
    scanf("%d", &N);
    for(cas=1; cas<=N; cas++)
    {
        scanf("%d:%d %d:%d", &wsh, &wsm, &weh, &wem);
        scanf("%d:%d %d:%d", &msh, &msm, &meh, &mem);
        ws=wsh*60+wsm;
        we=weh*60+wem;
        ms=msh*60+msm;
        me=meh*60+mem;
        if(ms<ws && me<ws)
        {
            printf("Case %d: Hits Meeting\n", cas);

        }
        else if(ms>we) printf("Case %d: Hits Meeting\n", cas);
        else printf("Case %d: Mrs Meeting\n", cas);

    }
    return 0;
}
