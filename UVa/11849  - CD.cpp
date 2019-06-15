//Accepted

#include<stdio.h>
long jack[1000005], jill[1000005];
int main()
{
    freopen("11849.txt","r",stdin);
    long i,j,k,a,b,Count;
    while(scanf("%ld %ld",&a,&b)==2)
    {
        Count=0;
        if(a==0 && b==0)
            break;
        for(i=0;i<a;i++)
            scanf("%ld",&jack[i]);
        for(i=0;i<b;i++)
            scanf("%ld",&jill[i]);
        for(i=0,k=0;i<a;i++)
        {
            for(j=k;j<b;j++)
            {
                if(jill[j]>jack[i])
                    break;
                if(jill[j]==jack[i])
                {
                    Count++;
                    j++;
                    break;
                }
            }
            k=j;
        }
        printf("%ld\n",Count);
    }
    return 0;
}
