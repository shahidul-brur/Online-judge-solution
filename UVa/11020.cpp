#include <stdio.h>
int main()
{
    freopen("11020.txt", "r", stdin);
    int test, cas, person, i, j, lastL, lastC, L, C, effi, lowestL, lowestC;
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        if(cas>1)
            printf("\n");
        printf("Case #%d:\n", cas);
        scanf("%d", &person);
        for(i=1, effi=0;i<=person;i++)
        {
            scanf("%d %d", &L, &C);
            if(i==1)
            {
                effi++;
                lastC=C;
                lastL=L;
                lowestC=C;
                lowestL=L;
            }
            else
            {
                if((L<lowestL && C<lowestC) || (L<lowestC && C<lowestL))
                {
                    effi=1;
                    lastC=C;
                    lastL=L;
                    lowestC=C;
                    lowestL=L;
                }
                else if((L<lastL && C<=lastC) || (L<=lastC && C<lastL))
                {
                    effi++;
                    lastC=C;
                    lastL=L;
                }
            }
            printf("%d\n", effi);
        }
    }
    return 0;
}
