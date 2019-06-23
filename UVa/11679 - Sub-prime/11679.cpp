//Accepted

#include <stdio.h>
int main()
{
    freopen("11679.txt", "r", stdin);
    int b, d, deb, cred, amount, bank[25], i, S;
    while(scanf("%d %d", &b, &d)!=EOF)
    {
        if(b==0 && d==0)
            break;
        for(i=1;i<=b;i++)
            scanf("%d", &bank[i]);
        for(i=1;i<=d;i++)
        {
            scanf("%d %d %d", &deb, &cred, &amount);
            bank[deb]=bank[deb]-amount;
            bank[cred]=bank[cred]+amount;
        }
        S=1;
        for(i=1;i<=b;i++)
        {
            if(bank[i]<0)
            {
                S=0;
                break;
            }
        }
        if(S==1)
            printf("S\n");
        else printf("N\n");
    }
    return 0;
}
