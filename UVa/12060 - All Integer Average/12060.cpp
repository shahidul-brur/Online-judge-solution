#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int gcd(int n1, int n2)
{
    if(n1%n2==0)
        return n2;
    else return gcd(n2, n1%n2);
}

int main()
{
    //freopen("12060.txt", "r", stdin);
    int n, sign, c=1, i, dgtP, dgtQ, dgtA, total, num, a, p, q, g, P, Q, A;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        total=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &num);
            total+=num;
        }
        if(total<0)
        {
            sign=1;
            total=0-total;
        }
        else
            sign=0;
        a=total/n;
        p=total-n*a;
        q=n;
        g=gcd(p,q);
        p=p/g;
        q=q/g;
        a=a+p/q;
        p=p-(p/q)*q;

        dgtP=dgtQ=dgtA=0;
        P=p;
        Q=q;
        A=a;
        while(P!=0)
        {
            dgtP++;
            P/=10;
        }
        while(Q!=0)
        {
            dgtQ++;
            Q/=10;
        }
        while(A!=0)
        {
            dgtA++;
            A/=10;
        }

        printf("Case %d:\n",c);
        if(q==1)
        {
            if(sign==1)
                printf("- ");
            printf("%d\n",a+p);
        }
        else if(a>0 && q>1)
        {
            if(sign==1)
                printf("  ");
            for(i=1;i<=dgtA;i++)
                printf(" ");
            for(i=1;i<=(dgtQ-dgtP);i++)
                printf(" ");
            printf("%d\n",p);
            if(sign==1)
                printf("- ");
            printf("%d",a);
            for(i=1;i<=dgtQ;i++)
                printf("-");
            printf("\n");
            if(sign==1)
                printf("  ");
            for(i=1;i<=dgtA;i++)
                printf(" ");
            printf("%d\n",q);
        }
        else if(a==0 && q>1)
        {
            if(sign==1)
                printf("  ");
            for(i=1;i<=(dgtQ-dgtP);i++)
                printf(" ");
            printf("%d\n",p);
            if(sign==1)
                printf("- ");
            for(i=1;i<=dgtQ;i++)
                printf("-");
            printf("\n");
            if(sign==1)
                printf("  ");
             printf("%d\n",q);
        }
        c++;
    }
    return 0;
}
