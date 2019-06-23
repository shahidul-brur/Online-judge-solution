//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("12482.txt", "r", stdin);
    int n, L, C, i, j, len, counL, counC, page;
    char word[75];
    while(scanf("%d %d %d", &n, &L, &C)!=EOF)
    {
        counC=0;
        counL=page=1;
        for(i=1;i<=n;i++)
        {
            scanf("%s\n", &word);
            len=strlen(word);
            if(i==1)
                counC+=len;
            else
                counC+=len+1;
            if(counC>C)
            {
                counC=len;
                counL++;
            }

            if(counL>L)
            {
                page++;
                counL=1;
            }

        }
        printf("%d\n",page);
    }
    return 0;
}
