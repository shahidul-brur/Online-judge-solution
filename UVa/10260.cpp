//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("10260.txt", "r", stdin);
    int value, len, i;
    char str[30];
    while(scanf("%s",str)!=EOF)
    {
        value=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if((str[i]=='B' || str[i]=='F' || str[i]=='P' || str[i]=='V') && value!=1)
            {
                printf("1");
                value=1;
            }
            else if((str[i]=='C' || str[i]=='G' || str[i]=='J' || str[i]=='K' || str[i]=='Q' || str[i]=='S' || str[i]=='X' || str[i]=='Z') && value!=2)
            {
                printf("2");
                value=2;
            }
            else if((str[i]=='D' || str[i]=='T') && value!=3)
            {
                printf("3");
                value=3;
            }
            else if(str[i]=='L' && value!=4)
            {
                printf("4");
                value=4;
            }
            else if((str[i]=='M' || str[i]=='N') && value!=5)
            {
                printf("5");
                value=5;
            }
            else if(str[i]=='R' && value!=6)
            {
                printf("6");
                value=6;
            }
            else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='H' || str[i]=='W' || str[i]=='Y')
                value=0;
        }
        printf("\n");
    }
    return 0;
}
