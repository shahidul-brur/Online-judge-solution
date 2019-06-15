//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10928.txt", "r", stdin);
    char in[50000];
    int len,i,j,min,n,v[1005],t,sp,a;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        getchar();
        min=100000;
        for(i=1;i<=n;i++)
        {
            gets(in);
            len=strlen(in);
            sp=0;
            for(j=0;j<len;j++)
                if(in[j]==' ')
                    sp++;
            if(sp<min)
                min=sp;
            v[i]=sp;
        }
        a=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==min)
            {
                if(a>0)
                    printf(" ");
                printf("%d",i);
                a++;
            }
        }
        printf("\n");
    }
    return 0;
}
