//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11965.txt", "r", stdin);
    int t,i,c,n,len,flag;
    char str[1000];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        if(c>1)
            printf("\n");
        printf("Case %d:\n",c);
        scanf("%d",&n);
        getchar();
        while(n--)
        {
            gets(str);
            len=strlen(str);
            for(i=0;i<len;i++)
            {
                flag=1;
                if(i>0)
                {
                    if(str[i]==' ')
                    {
                        if(str[i-1]==' ')
                            flag=0;
                    }

                }
                if(str[i]=='\t' || str[i]=='\r' && str[i]=='\v')
                    printf(" ");
                else if(flag==1)
                    printf("%c",str[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
