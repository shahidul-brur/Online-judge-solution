//Accepted

#include<stdio.h>
int main()
{
    freopen("694.txt", "r", stdin);
    long long int i,j,a,aa,l,count,c=1;
    while(scanf("%lld %lld", &a,&l)==2)
    {
        if(a<0 && l<0)
            break;
        aa=a;
        count=0;
        while(a<=l)
        {
            if(a%2==1)
            {
                a=3*a+1;
            }
            else if(a%2==0)
            {
                a=a/2;
            }
            count++;
            if(a==1)
            {
                count++;
                break;
            }
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",c,aa,l,count);
        c++;
    }
    return 0;
}

