//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("12541.txt", "r", stdin);
    int n,i,d[110],m[110],y[110],old,min,max,j;
    char name[25],nameY[25],nameE[25];
    scanf("%d",&n);
    scanf("%s",&name);
    scanf("%d %d %d",&d[0],&m[0],&y[0]);
    old=d[0]+m[0]*30+y[0]*365;
    min=old;
    max=old;
    strcpy(nameY,name);
    strcpy(nameE,name);
    for(i=1;i<n;i++)
    {
        scanf("%s",&name);
        scanf("%d %d %d",&d[i],&m[i],&y[i]);
        old=d[i]+m[i]*30+y[i]*365;
        if(old>max)
        {
            max=old;
            strcpy(nameY,name);
        }
        if(old<min)
        {
            min=old;
            strcpy(nameE,name);
        }
    }
    puts(nameY);
    puts(nameE);
    return 0;
}
