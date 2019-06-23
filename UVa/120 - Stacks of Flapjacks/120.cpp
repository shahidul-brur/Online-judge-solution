#include <stdio.h>
#include <string.h>
int aray[35];
void flip(int p)
{
    int temp = aray[0];
    aray[0] = aray[p];
    aray[p] = temp;
}
int main()
{
    char in[5];
    int num, n, i, j, maxi, mini, len;
    while(gets(in))
    {
        len = strlen(in);
        maxi = 0;
        mini = 110;
        num = 0;
        for(i = 0, j = 0; i <= len ; i++ )
        {
            if(in[i] == ' ' || i == len)
            {
                aray[j]=num;
                if(num > maxi)
                    maxi = j;
                if(num < mini)
                    mini = j;
                j++;
            }
            else num = num * 10 + in[i] - '0';
        }
        n = j;
        for(i = 0; i<n; i++)
        {
            if(i>0)
                printf(" ");
            printf("%d", aray[i]);
        }
        printf("\n");
        if(mini == 0 && maxi == n-1)
            printf("0\n");
        else if(mini == n-1 && maxi == 0)
            printf("1 0\n");
        else
        {
            if(maxi == 0)
                printf("1 ");

        }
    }
    return 0;
}
