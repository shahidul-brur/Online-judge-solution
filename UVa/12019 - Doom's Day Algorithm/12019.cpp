//Accepted

#include <stdio.h>
int main()
{
    freopen("12019.txt", "r", stdin);
    int t, m, d, day[15][35], i, j, b=1, td[13], p;
    td[1]=td[3]=td[5]=td[7]=td[8]=td[10]=td[12]=31;
    td[4]=td[6]=td[9]=td[11]=30;
    td[2]=28;
    for(i=1;i<=12;i++)
    {
        for(j=1;j<=td[i];j++)
        {
            day[i][j]=b;
            b++;
            if(b>7)
                b=1;
        }
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &d);
        p=day[m][d];
        if(p==1)
            printf("Saturday\n");
        else if(p==2)
            printf("Sunday\n");
        else if(p==3)
            printf("Monday\n");
        else if(p==4)
            printf("Tuesday\n");
        else if(p==5)
            printf("Wednesday\n");
        else if(p==6)
            printf("Thursday\n");
        else if(p==7)
            printf("Friday\n");
    }
    return 0;
}
