//Accepted

#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, t, b1, b2, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        m=n;
        b1=b2=0;
        while(m>0)
        {
            if(m%2==1)
                b1++;
            m/=2;
        }
        m=p=0;
        while(n>0)
        {
            m+=n%10*pow(16, p);
            n/=10;
            p++;
        }
        while(m>0)
        {
            if(m%2==1)
                b2++;
            m/=2;
        }
        printf("%d %d\n", b1, b2);
    }
    return 0;
}
