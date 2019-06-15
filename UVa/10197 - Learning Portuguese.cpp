/*

Problem: UVa 10197 - Learning Portuguese
Status: Accepted
Author: md. Shahidul Islam
Email: shahidul.cse.brur@gmail.com
University: Begum Rokeya University, Rangpur, Bangladesh
Department: Computer Science and engineering

*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    //freopen("10197.txt", "r", stdin);
    int i, cas=1, j, k, lenP, lenE;
    char port[32], eng[32], tv;
    while(scanf("%s %s", port, eng)!=EOF)
    {
        lenE=strlen(eng);
        lenP=strlen(port);
        tv=port[lenP-2];
        if(cas>1)
            printf("\n");
        printf("%s (to %s)\n", port, eng);
        if((tv!='i' && tv!='a' && tv!='e') || port[lenP-1]!='r')
            printf("Unknown conjugation\n");
        else
        {
            port[lenP-2]='\0';
            if(tv=='a' || tv=='e')
            {
                printf("%-9s %so\n", "eu", port);
                printf("%-9s %s%cs\n", "tu", port,tv);
                printf("%-9s %s%c\n", "ele/ela", port,tv);
                printf("n%c%-7s %s%cmos\n", 243, "s", port,tv);
                printf("v%c%-7s %s%cis\n", 243, "s", port,tv);
                printf("%-9s %s%cm\n", "eles/elas", port,tv);
            }
            else if(tv=='i')
            {
                printf("%-9s %so\n", "eu", port);
                printf("%-9s %ses\n", "tu", port);
                printf("%-9s %se\n", "ele/ela", port);
                printf("n%c%-7s %s%cmos\n", 243, "s", port,tv);
                printf("v%c%-7s %s%cs\n", 243, "s", port,tv);
                printf("%-9s %sem\n", "eles/elas", port);
            }
        }
        cas++;
    }
    return 0;
}
