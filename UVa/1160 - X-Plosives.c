#include<stdio.h>
int main()
{
    freopen("1160.txt", "r", stdin);
    long long int i,j,k,n[10000],f1,p,f2,count;
    while(scanf("%lld %lld",&n[1],&n[2])!=EOF)
    {
        count=0;
        i=3;
        scanf("%lld",&p);
        while(p!=-1)
        {
            f1=f2=0;
            n[i]=p;
            scanf("%lld",&n[i+1]);
            scanf("%lld",&p);
            for(j=1;j<i;j++)
            {
                if(n[i]==n[j])
                {
                    f1=1;
                    break;
                }
            }
            for(j=1;j<i;j++)
            {
                if(n[i+1]==n[j])
                {

                    f2=1;
                    break;
                }
            }
            if(f1==1 && f2==1)
            {
                count++;
            }
            i+=2;
        }
        printf("%lld\n",count);
    }
    return 0;
}
