//Accepted
#include<stdio.h>
int main()
{
    freopen("350.txt", "r", stdin);
    long long int n,z,i,l,m,c=1,count,v[100000],j,br;
    while(scanf("%lld %lld %lld %lld",&z,&i,&m,&l)!=EOF)
    {
        if(z==0 && i==0 && l==0 && m==0)
            break;
        v[0]=l;
        count=0;
        for(;;)
        {
            br=0;
            l=(z*l+i)%m;
            v[count]=l;
            count++;
            for(j=0;j<count-1;j++)
            {
                if(l==v[j])
                {
                    br=1;
                }
            }
            if(br==1)
                break;
        }
        printf("Case %lld: %lld\n",c,count-1);
        c++;
    }
    return 0;
}
