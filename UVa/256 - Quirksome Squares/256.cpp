//Accepted

#include <stdio.h>
int main()
{
    int n, i, L, R, q2[10], q4[100], q6[1000], q8[10000], a, b, c, d;
    a=b=c=d=0;
    for(i=0;i<=9;i++)
    {
        L=i*i/10;
        R=i*i%10;
        if((L+R)==i)
            q2[a++]=i*i;
    }
    for(i=0;i<=99;i++)
    {
        L=i*i/100;
        R=i*i%100;
        if((L+R)==i)
            q4[b++]=i*i;
    }
    for(i=0;i<=999;i++)
    {
        L=i*i/1000;
        R=i*i%1000;
        if((L+R)==i)
            q6[c++]=i*i;
    }
    for(i=0;i<=9999;i++)
    {
        L=i*i/10000;
        R=i*i%10000;
        if((L+R)==i)
            q8[d++]=i*i;
    }

    while(scanf("%d", &n)!=EOF)
    {
        if(n==2)
        {
            for(i=0;i<a;i++)
                printf("%02d\n", q2[i]);
        }
        else if(n==4)
        {
            for(i=0;i<b;i++)
                printf("%04d\n", q4[i]);
        }
        else if(n==6)
        {
            for(i=0;i<c;i++)
                printf("%06d\n", q6[i]);
        }
        else if(n==8)
        {
            for(i=0;i<d;i++)
                printf("%08d\n", q8[i]);
        }
    }
    return 0;
}
