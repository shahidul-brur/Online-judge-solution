#include <iostream>
#include <stdio.h>
using namespace std;
double totalCalory, totalFatCalory, TT, TF;
int fat, protein, sugar, starch, alcohol, percent;
char unitF, unitP, unitS, unitSt, unitA, line[100];
void calculate()
{
    sscanf(line, "%d\n%c %d\n%c %d\n%c %d\n%c %d\n%c", &fat, &unitF, &protein, &unitP, &sugar, &unitS, &starch, &unitSt, &alcohol, &unitA);
    if(unitF=='%')
        percent+=fat;
    if(unitP=='%')
        percent+=protein;
    if(unitSt=='%')
        percent+=starch;
    if(unitS=='%')
        percent+=sugar;
    if(unitA=='%')
        percent+=alcohol;

    if(unitF=='g')
        totalCalory+=9*fat, totalFatCalory+=9*fat;
    else if(unitF=='C')
        totalFatCalory+=fat, totalCalory+=fat;

    if(unitP=='g')
        totalCalory+=4*protein;
    else if(unitF=='C')
        totalCalory+=protein;

    if(unitS=='g')
        totalCalory+=4*sugar;
    else if(unitS=='C')
        totalCalory+=sugar;

    if(unitSt=='g')
        totalCalory+=4*starch;
    else if(unitSt=='C')
        totalCalory+=starch;

    if(unitA=='g')
        totalCalory+=7*alcohol;
    else if(unitA=='C')
        totalCalory+=alcohol;

    if(unitF=='%')
        totalFatCalory+=(totalCalory*fat)/(100-percent), totalCalory+=(totalCalory*fat)/(100-percent);
    if(unitP=='%')
        totalCalory+=(totalCalory*protein)/(100-percent);
    if(unitS=='%')
        totalCalory+=(totalCalory*sugar)/(100-percent);
    if(unitSt=='%')
        totalCalory+=(totalCalory*starch)/(100-percent);
    if(unitA=='%')
        totalCalory+=(totalCalory*alcohol)/(100-percent);
}
int main()
{
    freopen("10554.txt", "r", stdin);
    while(gets(line))
    {
        if(line[0]=='-')
            break;
        TT=TF=percent=totalCalory=totalFatCalory=0;
        calculate();
        while(gets(line))
        {
            if(line[0]=='-')
                break;
            percent=totalCalory=totalFatCalory=0;
            calculate();
            TT+=totalCalory;
            TF+=totalFatCalory;
        }
        printf("%d%%\n", TF*100/TT);
    }
    return 0;
}
