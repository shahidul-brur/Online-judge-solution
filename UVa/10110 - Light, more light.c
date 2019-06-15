//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int n,r;
    while(scanf("%llu",&n)!=EOF)
    {
        if(n==0)
            break;
        r=sqrt(n);
        if(r*r==n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
