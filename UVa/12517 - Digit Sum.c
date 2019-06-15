#include<stdio.h>
int digitSum(int a)
{
    int i,s=0;
    while(a>0)
    {
       s+=a%10;
       a=a/10;
    }
    return s;
}
int main()
{
    //freopen("12517.txt", "r", stdin);
    int a,b,sum,i;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        sum=0;
        if(a==0 && b==0)
            break;
        for(i=a;i<=b;i++)
            sum+=digitSum(i);
        printf("%d\n",sum);
    }
    return 0;
}
