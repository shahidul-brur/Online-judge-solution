//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("10921.txt", "r", stdin);
    int i,len;
    char code[35];
    while(gets(code))
    {
        len=strlen(code);
        for(i=0;i<len;i++)
        {
            if(code[i]=='A' || code[i]=='B' || code[i]=='C')
                code[i]='2';
            if(code[i]=='D' || code[i]=='E' || code[i]=='F')
                code[i]='3';
            if(code[i]=='G' || code[i]=='H' || code[i]=='I')
                code[i]='4';
            if(code[i]=='J' || code[i]=='K' || code[i]=='L')
                code[i]='5';
            if(code[i]=='M' || code[i]=='N' || code[i]=='O')
                code[i]='6';
            if(code[i]=='P' || code[i]=='Q' || code[i]=='R' || code[i]=='S')
                code[i]='7';
            if(code[i]=='T' || code[i]=='U' || code[i]=='V')
                code[i]='8';
            if(code[i]=='W' || code[i]=='X' || code[i]=='Y' || code[i]=='Z')
                code[i]='9';
        }
        puts(code);
    }
    return 0;
}
