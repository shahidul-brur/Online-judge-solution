//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    int len,i;
    char str[999999];
    while(gets(str)){
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='k'||str[i]=='K')
            printf("h");
        else if(str[i]==' ')
            printf(" ");
        else if(str[i]=='[')
            printf("o");
        else if(str[i]=='\'')
            printf("l");
        else if(str[i]=='r'||str[i]=='R')
            printf("w");
        else if(str[i]=='d'||str[i]=='D')
            printf("a");
        else if(str[i]=='y'||str[i]=='Y')
            printf("r");
        else if(str[i]=='t'||str[i]=='T')
            printf("e");
        else if(str[i]=='i'||str[i]=='I')
            printf("y");
        else if(str[i]=='o'||str[i]=='O')
            printf("u");
        else if(str[i]=='p'||str[i]=='P')
            printf("i");
        else if(str[i]=='u'||str[i]=='U')
            printf("t");
        else if(str[i]=='e'||str[i]=='E')
            printf("q");
        else if(str[i]=='l'||str[i]=='L')
            printf("j");
        else if(str[i]=='j'||str[i]=='J')
            printf("g");
        else if(str[i]=='h'||str[i]=='H')
            printf("f");
        else if(str[i]=='g'||str[i]=='G')
            printf("d");
        else if(str[i]=='f'||str[i]=='F')
            printf("s");
        else if(str[i]=='d'||str[i]=='D')
            printf("a");
        else if(str[i]=='m'||str[i]=='M')
            printf("b");
        else if(str[i]=='n'||str[i]=='N')
            printf("v");
        else if(str[i]=='b'||str[i]=='B')
            printf("c");
        else if(str[i]=='v'||str[i]=='V')
            printf("x");
        else if(str[i]=='c'||str[i]=='C')
            printf("z");
        else if(str[i]=='.')
            printf("m");
        else if(str[i]==',')
            printf("n");
        else if(str[i]=='/')
            printf(",");
        else if(str[i]==';')
            printf("k");
        else if(str[i]==']')
            printf("p");
        else if(str[i]=='=')
            printf("0");
        else if(str[i]=='-')
            printf("9");
        else if(str[i]=='0')
            printf("8");
        else if(str[i]=='9')
            printf("7");
        else if(str[i]=='8')
            printf("6");
        else if(str[i]=='7')
            printf("5");
        else if(str[i]=='6')
            printf("4");
        else if(str[i]=='5')
            printf("3");
        else if(str[i]=='4')
            printf("2");
        else if(str[i]=='3')
            printf("1");
        else if(str[i]=='2')
            printf("`");
        else
            printf("%c",str[i]);
    }
    printf("\n");
    }
    return 0;
}
