//Accepted

#include<stdio.h>
int main()
{
    freopen("11777.txt", "r", stdin);
    int t,i,num[8],ct,j,k,min,total;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        ct=0;
        for(j=1;j<=7;j++)
            scanf("%d",&num[j]);
        if(num[5]>num[6])
        {
            ct+=num[5];
            min=num[6];
        }
        else
        {
            ct+=num[6];
            min=num[5];
        }
        if(num[7]>min)
            ct+=num[7];
        else ct+=min;
        ct/=2;
        total=num[1]+num[2]+num[3]+num[4]+ct;
        printf("%d\n",total);
        if(total>=90)
            printf("Case %d: A\n",i);
        if(total>=80 && total<90)
            printf("Case %d: B\n",i);
        if(total>=70 && total<80)
            printf("Case %d: C\n",i);
        if(total>=60 && total<70)
            printf("Case %d: D\n",i);
        if(total<60)
            printf("Case %d: F\n",i);

    }
    return 0;
}
