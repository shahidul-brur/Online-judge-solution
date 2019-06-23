#include<stdio.h>
main()
{
    long long int n,even=0,odd=0,d;
    scanf("%lld",&n);
    if(n==0)
        even=1;
    while(n!=0)
    {
        d=n%10;
        if(d%2==0)
            even++;
       /* else if(d%2==1)*/
       else
            odd++;
        n/=10;
    }
    printf("Number of even %d ",even);
    printf("Number of odd %d ",odd);
}
