/*Accepted*/

#include<stdio.h>
int main()
{
    freopen("11219.txt", "r",stdin);
    int t,cd,cm,cy,bd,bm,by,i,c,b;
    int age;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d/%d/%d",&cd,&cm,&cy);
        scanf("%d/%d/%d",&bd,&bm,&by);
        c=cd+cm*30+cy*365;
        b=bd+bm*30+by*365;
        if(c<b) printf("Case #%d: Invalid birth date\n",i);
        else
        {
            age=(c-b)/365;
            if(age>130) printf("Case #%d: Check birth date\n",i);
            else
            {
                printf("Case #%d: %d\n",i,age);
            }
        }
    }
    return 0;
}
