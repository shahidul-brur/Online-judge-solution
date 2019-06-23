//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("489.txt", "r", stdin);
    int round, lenS, lenG, C[28], W[28], repeat[28], S[28], i, j, stroke, mark, p;
    char  sol[500], guess[500];
    while(scanf("%d", &round)&& round!=-1)
    {
        scanf("%s", sol);
        scanf("%s", guess);
        lenS=strlen(sol);
        lenG=strlen(guess);
        memset(C, 0, sizeof(C));
        memset(W, 0, sizeof(W));
        memset(repeat, 0, sizeof(repeat));
        memset(S, 0, sizeof(S));
        for(i=0;i<lenS;i++)
        {
            p=sol[i]-'a';
            S[p]=1;
            repeat[p]++;
        }
        mark=0;
        stroke=0;
        for(i=0;i<lenG;i++)
        {
            p=guess[i]-'a';
            if(S[p]==1 && C[p]==0)
            {
                C[p]=1;
                mark+=repeat[p];
            }
            else if(S[p]==0 && W[p]==0)
            {
                W[p]=1;
                stroke+=1;
            }
           if(mark==lenS || stroke==7)
                break;

        }
        printf("Round %d\n",round);
        if(mark==lenS)
            printf("You win.\n");
        else if(stroke==7)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}
