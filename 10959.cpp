#include <stdio.h>
#define M 50000
int main()
{
    freopen("10959.txt", "r", stdin);
    int Gio[1009], c, t, p, d, i, j, L[500000], R[500000], cnt;
    Gio[0]=0;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d",&p,&d);
        for(i=1;i<p;i++)
            Gio[i]=M;
        cnt=0;
        for(i=1;i<=d;i++)
        {
            scanf("%d %d",&L[i], &R[i]);
            if(L[i]==0)
            {
                Gio[R[i]]=1;
                cnt++;
                continue;
            }
            else if(R[i]==0)
            {
                Gio[L[i]]=1;
                cnt++;
                continue;
            }
            if(Gio[L[i]]!=M)
            {
                if(Gio[L[i]]+1<Gio[R[i]])
                {
                    if(Gio[R[i]]==M)
                        cnt++;
                    Gio[R[i]]=Gio[L[i]]+1;
                }
            }
            if(Gio[R[i]]!=M)
            {
                if(Gio[R[i]]+1<Gio[L[i]])
                {
                    if(Gio[L[i]]==M)
                        cnt++;
                    Gio[L[i]]=Gio[R[i]]+1;
                }
            }

        }
        for(i=1;i<=d;i++)
        {
            if(Gio[L[i]]!=M)
            {
                if(Gio[L[i]]+1<Gio[R[i]])
                {
                    if(Gio[R[i]]==M)
                        cnt++;
                    Gio[R[i]]=Gio[L[i]]+1;
                }
            }
            if(Gio[R[i]]!=M)
            {
                if(Gio[R[i]]+1<Gio[L[i]])
                {
                    if(Gio[L[i]]==M)
                        cnt++;
                    Gio[L[i]]=Gio[R[i]]+1;
                }
            }

        }
        if(c>1)
            printf("\n");
        for(i=1;i<p;i++)
        {
            printf("%d\n",Gio[i]);
        }
    }
    return 0;
}
