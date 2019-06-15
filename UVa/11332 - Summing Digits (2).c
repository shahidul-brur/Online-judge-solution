#include<stdio.h>
int main()
{
    int n,sum;
    while(scanf("%d",&n) && n!=0)
    {
        sum=digSum(n);
        printf("%d\n",sum);
    }
    int digSum(int n)
    {
        int rem,dig=0;
        while(n!=0)
        {
            rem=n%10;
            dig+=rem;
            n/=10;
        }
        if(dig>9)
            digSum(dig);
        return dig;
    }
    return 0;
}
