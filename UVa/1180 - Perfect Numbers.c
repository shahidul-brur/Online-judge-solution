#include<stdio.h>
int main()
{
    char ch;
    long long int t,p;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&p);
        if(t)
            scanf(" %c",&ch);
        if(p==2||p==3||p==5||p==7||p==13||p==17)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
