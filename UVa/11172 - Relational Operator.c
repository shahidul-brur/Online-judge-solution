//Accepted

#include<stdio.h>
int main()
{
    int t;
    long long int a,b;
    char l='<', g='>', eq='=';
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        if(a<b)
            printf("%c\n",l);
        else if(a>b)
            printf("%c\n",g);
        else if(a==b)
            printf("%c\n",eq);
    }
    return 0;
}
