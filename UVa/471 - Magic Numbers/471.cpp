//Accepted

#include <stdio.h>
int main()
{
    freopen("471.txt", "r", stdin);
    long long t, n, cas, i, nomi, mul, j, temp, Y, digit[15], d, dg[15], d1;
    scanf("%lld", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lld", &n);
        if(cas>1)
            printf("\n");
        for(nomi=1;nomi<=9876543210;nomi++)
        {
            mul=nomi*n;
            if(mul>9876543210)
                break;
            Y=1;
            d=d1=0;

            temp=nomi;
            while(temp>0)
            {
                dg[d1++]=temp%10;
                temp/=10;
            }
            for(i=0;i<d1-1;i++)
            {
                for(j=i+1;j<d1;j++)
                {
                    if(dg[i]==dg[j])
                    {
                        Y=0;
                        break;
                    }
                }
                if(Y==0)
                    break;
            }

            temp=mul;
            while(temp>0)
            {
                digit[d++]=temp%10;
                temp/=10;
            }
            for(i=0;i<d-1;i++)
            {
                for(j=i+1;j<d;j++)
                {
                    if(digit[i]==digit[j])
                    {
                        Y=0;
                        break;
                    }
                }
                if(Y==0)
                    break;
            }
            if(Y==1)
                printf("%lld / %lld = %lld\n", mul, nomi, n);
        }
    }
    return 0;
}
