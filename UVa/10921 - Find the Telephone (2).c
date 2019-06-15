#include<stdio.h>
#include<string.h>
int main()
{

    char str[40],i,len;
    while(gets(str)!=EOF)
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(strcmp(str[i], "A") || strcmp(str[i], "B") || strcmp(str[i], "C"))
                str[i]="2";
            else if(strcmp(str[i], "D") || strcmp(str[i], "E") || strcmp(str[i], "F"))
             str[i]="3";
            else if(strcmp(str[i], "G") || strcmp(str[i], "H") || strcmp(str[i], "I"))
             str[i]="4";
            else if(strcmp(str[i], "J") || strcmp(str[i], "L") || strcmp(str[i], "L"))
             str[i]="5";
            else if(strcmp(str[i], "M") || strcmp(str[i], "N") || strcmp(str[i], "O"))
             str[i]="6";
            else if(strcmp(str[i], "P") || strcmp(str[i], "Q") || strcmp(str[i], "R") || strcmp(str[i], "S"))
             str[i]="7";
            else if(strcmp(str[i], "T") || strcmp(str[i], "U") || strcmp(str[i], "V"))
             str[i]="8";
            else if(strcmp(str[i], "W") || strcmp(str[i], "X") || strcmp(str[i], "Y") || strcmp(str[i], "Z"))
             str[i]="9";
        }
    }
    return 0;
}
