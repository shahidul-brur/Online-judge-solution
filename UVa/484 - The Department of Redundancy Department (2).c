#include<stdio.h>
int main()
{
    char num[10000];
    int n[10000];
    while(gets(num))
    {
        atoi(num);
        printf("%d",num[4]);
    }
}
