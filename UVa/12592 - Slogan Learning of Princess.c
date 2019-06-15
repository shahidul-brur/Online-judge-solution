//Accepted

#include<stdio.h>
#include<string.h>
struct slogan{
char in[110];
char out[110];
};
int main()
{
    freopen("12592.txt", "r", stdin);
    int n, q,i,j,k;
    struct slogan SL[25];
    char query[110];
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        gets(SL[i].in);
        gets(SL[i].out);
    }
    scanf("%d",&q);
    getchar();
    for(i=1;i<=q;i++)
    {
        gets(query);
        for(j=1;j<=n;j++)
            if(strcmp(query, SL[j].in)==0)
            {
                puts(SL[j].out);
                break;
            }
    }
    return 0;
}
