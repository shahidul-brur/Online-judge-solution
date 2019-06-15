#include<stdio.h>
#include<string.h>
int main()
{
    freopen("306.txt", "r", stdin);
    char msg[5000],in[5000],out[5000];
    long int n, c,p[250],k,i,len,j;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);

        while(scanf("%d",&k)&&k!=0)
        {
            getchar();
            gets(msg);
            len=strlen(msg);
            if(len<n)
            {
                for(i=len;i<n;i++)
                    msg[i]=' ';
                msg[n]='\0';
            }
            c=k%n;
            for(i=1;i<=c;i++)
            {
                for(j=0;j<n;j++)
                {
                    out[p[j]-1]=msg[j];
                }
                out[j]='\0';
                strcpy(msg,out);
            }
            puts(out);
        }
        printf("\n");
    }
    return 0;
}
