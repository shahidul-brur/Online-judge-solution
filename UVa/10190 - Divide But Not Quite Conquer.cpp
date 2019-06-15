//Accepted

#include <iostream>
#include <math.h>
#include <stdio.h>

int main()
{
    //freopen("10190.txt", "r", stdin);
    int n, m, d, i, fun, seq[1000], s;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        if(m<2 || n<2 || n<m)
        {
            printf("Boring!\n");
            continue;
        }
        else
        {
            fun=1;
            s=1;
            d=n;
            while(d>1)
            {
                if(d%m!=0)
                {
                    fun=0;
                    break;
                }
                else if(d%m==0)
                {
                    seq[s++]=d;
                    d/=m;
                }
            }
            seq[s]=d;
            if(d!=1)
                fun=0;
            if(fun==0)
                printf("Boring!\n");
            else
            {
                for(i=1;i<s;i++)
                    printf("%d ", seq[i]);

                printf("%d\n", seq[s]);
            }
        }
    }
    return 0;
}
