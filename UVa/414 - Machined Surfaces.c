/*ACCEPTED*/


#include<stdio.h>
#include<string.h>
int main()
{
    freopen("414.txt", "r", stdin);
    char str[1000][1000];
    long i,j,n,total,sp[20],min,k,ans;
    while(scanf("%ld",&n)!=EOF)
    {
        getchar();
        if(n==0)
            break;
        for(i=0;i<n;i++)
            gets(str[i]);
        total=0;
        min=50;
        for(i=0;i<n;i++)
        {
            sp[i]=0;
            for(j=0;j<25;j++)
            {
                if(str[i][j]==' ')
                    sp[i]++;
            }
            if(sp[i]<min)
                min=sp[i];
            total+=sp[i];
        }
        if(total==0)
            printf("0\n");
        else
        {
            ans=total-n*min;
            printf("%ld\n",ans);
        }
    }
    return 0;
}
