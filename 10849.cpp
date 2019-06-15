#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("10849.txt", "r", stdin);
    int t, c, n, rFrom, cFrom, rTo, cTo, i, j, from, to;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d", &t);
        scanf("%d", &n);
        while(t--)
        {
            scanf("%d %d %d %d", &rFrom, &cFrom, &rTo, &cTo);

            // 1 means black, 0 means white
            if((rFrom%2==0 && cFrom%2==0) || (rFrom%2==1 && cFrom%2==1))
                from=1; // black
            else
                from=0; // white
            if((rTo%2==0 && cTo%2==0) || (rTo%2==1 && cTo%2==1))
                to=1;   // black
            else
                to=0;    // white

            if(from!=to) // black to white or white to black impossible
                printf("no move\n");
            else if(rFrom == rTo && rTo == cTo)
                printf("0\n");
            else
            {
                if(abs(rTo - rFrom) == abs(cTo - cFrom))
                    printf("1\n");
                else
                    printf("2\n");
            }
        }
    }
    return 0;
}
