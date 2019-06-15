//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10082.txt", "r", stdin);
    char str[99999];
    int i,len;
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='=')
                printf("-");
            else if(str[i]=='-')
                printf("0");
            else if(str[i]=='0')
                printf("9");
            else if(str[i]=='9')
                printf("8");
            else if(str[i]=='8')
                printf("7");
            else if(str[i]=='7')
                printf("6");
            else if(str[i]=='6')
                printf("5");
            else if(str[i]=='5')
                printf("4");
            else if(str[i]=='4')
                printf("3");
            else if(str[i]=='3')
                printf("2");
            else if(str[i]=='2')
                printf("1");
            else if(str[i]=='1')
                printf("`");

            else if(str[i]=='\\')
                printf("]");
            else if(str[i]==']')
                printf("[");
            else if(str[i]=='[')
                printf("P");
            else if(str[i]=='P')
                printf("O");
            else if(str[i]=='O')
                printf("I");
            else if(str[i]=='I')
                printf("U");
            else if(str[i]=='U')
                printf("Y");
            else if(str[i]=='Y')
                printf("T");
            else if(str[i]=='T')
                printf("R");
            else if(str[i]=='R')
                printf("E");
            else if(str[i]=='E')
                printf("W");
            else if(str[i]=='W')
                printf("Q");
            else if(str[i]=='\'')
                printf(";");
            else if(str[i]==';')
                printf("L");
            else if(str[i]=='L')
                printf("K");
            else if(str[i]=='K')
                printf("J");
            else if(str[i]=='J')
                printf("H");
            else if(str[i]=='H')
                printf("G");
            else if(str[i]=='G')
                printf("F");
            else if(str[i]=='F')
                printf("D");
            else if(str[i]=='D')
                printf("S");
            else if(str[i]=='S')
                printf("A");
            else if(str[i]=='/')
                printf(".");
            else if(str[i]=='.')
                printf(",");
            else if(str[i]==',')
                printf("M");
            else if(str[i]=='M')
                printf("N");
            else if(str[i]=='N')
                printf("B");
            else if(str[i]=='B')
                printf("V");
            else if(str[i]=='V')
                printf("C");
            else if(str[i]=='C')
                printf("X");
            else if(str[i]=='X')
                printf("Z");
            else
                printf("%c",str[i]);

        }
        printf("\n");
    }
    return 0;
}
