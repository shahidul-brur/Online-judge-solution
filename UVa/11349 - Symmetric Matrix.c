//Accepted
#include<stdio.h>
int main()
{
    //freopen("11349.txt", "r", stdin);
    long long int t,n,i,j,c,sym, M[10000];
    char ch;
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        sym=1;
        for(i=1;i<=4;i++)
            scanf("%c",&ch);
        scanf("%lld",&n);
        for(i=0;i<n*n;i++)
        {
            scanf("%lld",&M[i]);
            if(M[i]<0)
                sym=0;
        }
        if(sym==1)
        {
            for(i=0,j=n*n-1;i<n*n/2;i++,j--)
            {
                if(M[i]!=M[j])
                {
                    sym=0;
                    break;
                }
            }
        }
        if(sym==1)
            printf("Test #%lld: Symmetric.\n",c);
        else
            printf("Test #%lld: Non-symmetric.\n",c);
    }
    return 0;
}
