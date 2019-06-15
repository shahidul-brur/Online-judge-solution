//Accepted

#include <stdio.h>
int main()
{
    freopen("10683.txt", "r", stdin);
    int H, M, S, C, time, con;
    while(scanf("%d", &time)!=EOF)
    {
        C=time%100;
        time/=100;
        S=time%100;
        time/=100;
        M=time%100;
        time/=100;
        H=time%100;
        time/=100;

        S=S+M*60+H*3600;
        C=C+S*100;

        con=C*125/108;
        printf("%07d\n",con);
    }
    return 0;
}
