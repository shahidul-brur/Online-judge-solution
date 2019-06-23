#include <stdio.h>
#include <string.h>
int main()
{
    freopen("12896.txt", "r", stdin);
    int t, L, i, j, num[105], time[105];
    char letter[12][7];
    strcpy(letter[0], " ");
    strcpy(letter[1], ".,?\"");
    strcpy(letter[2], "abc");
    strcpy(letter[3], "def");
    strcpy(letter[4], "ghi");
    strcpy(letter[5], "jkl");
    strcpy(letter[6], "mno");
    strcpy(letter[7], "pqrs");
    strcpy(letter[8], "tuv");
    strcpy(letter[9], "wxyz");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&L);
        for(i=1;i<=L;i++)
            scanf("%d", &num[i]);
        for(i=1;i<=L;i++)
        {
            scanf("%d", &time[i]);
            printf("%c",letter[num[i]][time[i]-1]);
        }
        printf("\n");

    }
    return 0;
}
