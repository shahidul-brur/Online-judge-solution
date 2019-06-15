#include<stdio.h>
int main()
{
    //freopen("371.txt", "r", stdin);
    long long int i,j,a,b,c,t,val,max,sc;
    while(scanf("%lld %lld", &i,&j)!=EOF){
            if(i==0 && j==0)
            break;
    max=0;
    if(i>j)
    {
        a=j;
        b=i;
    }
    else
    {
        a=i;
        b=j;
    }
    for(t=a;t<=b;t++)
    {
        c=t;
        val=0;
        do
        {
            if(c%2==1)
            {
                c=3*c+1;
                val++;
            }
            else if(c%2==0)
            {
                c=c/2;
                val++;
            }
            if(val>max)
            {
                max=val;
                sc=t;
            }
        }while(c!=1);
    }
    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,sc,max);
    }
    return 0;
}

