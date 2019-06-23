#include <stdio.h>
int main()
{
    long int t, c, i, x, y, m, found;
    scanf("%ld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%ld %ld",&x,&y);
        found=0;
        for(i=y-2;i<=x;i++)
        {
            if(i>0)
                if(x%i==y-2)
                {
                    m=i;
                    found=1;
                    break;
                }
        }
        if(found==1)
            printf("%ld\n",m);
        else
            printf("Impossible\n");
    }
    return 0;
}
