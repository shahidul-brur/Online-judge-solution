//Accepted

#include<stdio.h>
int main()
{
    int n,l,u,i,j,max=0,count=0,div,t;
    while(scanf("%d",&n)!=EOF){
    for(t=0;t<n;t++)
    {
       scanf("%d %d",&l,&u);
       for(i=l;i<=u;i++)
       {
            for(j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    count+=2;
                }
                if(j*j==i) count--;
            }
            if(count>max)
            {
                div=i;
                max=count;
            }
            count=0;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,div,max);
        max=0;
    }

    }
    return 0;
}
