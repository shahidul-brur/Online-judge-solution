//Accepted

#include<stdio.h>
int main()
{
    freopen("11743.txt", "r", stdin);
    int t,n,d1,d2,d3,d4,d5,d6,d7,d8,num1,num2,num3,num4,dsum,usum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
        d1=2*(num1/1000);
        if(d1>9)
            d1=d1/10+d1%10;
        d2=2*(num2/1000);
        if(d2>9)
            d2=d2/10+d2%10;
        d3=2*(num3/1000);
        if(d3>9)
            d3=d3/10+d3%10;
        d4=2*(num4/1000);
        if(d4>9)
            d4=d4/10+d4%10;
        d5=2*((num1%100)/10);
        if(d5>9)
            d5=d5/10+d5%10;
        d6=2*((num2%100)/10);
        if(d6>9)
            d6=d6/10+d6%10;
        d7=2*((num3%100)/10);
        if(d7>9)
            d7=d7/10+d7%10;
        d8=2*((num4%100)/10);
        if(d8>9)
            d8=d8/10+d8%10;
        dsum=d1+d2+d3+d4+d5+d6+d7+d8;
        usum=(num1%1000)/100+(num2%1000)/100+(num3%1000)/100+(num4%1000)/100+num1%10+num2%10+num3%10+num4%10;
        n=dsum+usum;
        if(n%10==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
