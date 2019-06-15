//Accepted

#include<stdio.h>
int main()
{
    //freopen("11942.txt", "r", stdin);
    int t, num[15],i;
    scanf("%d",&t);
    printf("Lumberjacks:\n");
    while(t--)
    {
        for(i=1;i<=10;i++)
            scanf("%d",&num[i]);
        if(num[1]<num[2] && num[2]<num[3] && num[3]<num[4] && num[4]<num[5] && num[5]<num[6] && num[6]<num[7] && num[7]<num[8] && num[8]<num[9] && num[9]<num[10])
            printf("Ordered\n");
        else if(num[1]>num[2] && num[2]>num[3] && num[3]>num[4] && num[4]>num[5] && num[5]>num[6] && num[6]>num[7] && num[7]>num[8] && num[8]>num[9] && num[9]>num[10])
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
