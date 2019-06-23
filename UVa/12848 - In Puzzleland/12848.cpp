//Accepted
#include <stdio.h>
int gcd(int n1, int n2)
{
    if(n1%n2==0)
        return n2;
    else return gcd(n2, n1%n2);
}

int main()
{
    int t, c, h1, s, h2, a, p, q, g;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d %d", &h1, &s, &h2);
        a=s/(h1-1);
        p=s-(h1-1)*a;
        a=a*(h2-1);
        p=p*(h2-1);
        q=(h1-1);
        g=gcd(p,q);
        p=p/g;
        q=q/g;
        a=a+p/q;
        p=p-(p/q)*q;

        printf("Case %d:",c);
        if(q==1)
            printf(" %d\n",a+p);
        else if(a>0 && q>1)
            printf(" %d %d/%d\n", a, p, q);
        else if(a==0 && q>1)
            printf(" %d/%d\n",p,q);

    }
    return 0;
}
