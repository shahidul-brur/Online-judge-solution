#include<stdio.h>
int main()
{
    int name[30];
    float salary,bonous,total;
    scanf("%s",&name);
    scanf("%f %f",&salary,&bonous);
    total=0.15*bonous+salary;
    printf("TOTAL = R$ %.2f\n",total);
    return 0;
}
