//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("340.txt", "r", stdin);
    int n, game=1, secret[1005], guess[1005], strong, weak, i, j, zero, taken[1005];
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;

        for(i=0;i<n;i++)
        {
            scanf("%d",&secret[i]);
        }

        printf("Game %d:\n",game);

        zero=0;
        while(zero<n)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&guess[i]);
                if(guess[i]==0)
                    zero++;
            }
            if(zero==n)
                break;

            weak=0;
            strong=0;

            memset(taken, 0, n*4);

            for(i=0;i<n;i++)
            {
                if(guess[i]==secret[i])
                {
                    strong++;
                    taken[i]=1;
                }
                else
                {
                    for(j=0;j<n;j++)
                        if(secret[j]==guess[i] && taken[j]==0 && guess[j]!=secret[j])
                        {
                            weak++;
                            taken[j]=1;
                            break;
                        }
                }
            }
            printf("    (%d,%d)\n",strong,weak);
        }
        game++;
    }
    return 0;
}
