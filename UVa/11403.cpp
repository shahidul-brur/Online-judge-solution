//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11403.txt", "r", stdin);
    int i, j, k, cas=1, xL, yL, mulL, L;
    long long a, b, ans, p, div, rem;
    char x[35], y[35], mul[500];
    while(scanf("%s %s", &x, &y)!=EOF)
    {
        if(strcmp(x, "0")==0 && strcmp(y, "0")==0)
            break;

        a=b=ans=0;
        xL=strlen(x);
        yL=strlen(y);
        p=1;
        for(i=xL-1;i>=0;i--)
        {
            a=a+(x[i]-'0')*p;
            p*=2;
        }
        p=1;
        for(i=yL-1;i>=0;i--)
        {
            b=b+(y[i]-'0')*p;
            p*=2;
        }
        ans=a*b;
        div=ans;
        i=0;
        while(div>0)
        {
            rem=div%2;
            div/=2;
            mul[i++]=rem+'0';
        }
        mul[i]='\0';
        mulL=strlen(mul);

        if(cas>1)
            printf("\n");
        L=xL > yL ? xL : yL;
        for(i=1;i<=(mulL-xL);i++)
            printf(" ");
        printf("%s\n", x);
        for(i=1;i<=(mulL-yL);i++)
            printf(" ");
        printf("%s\n", y);
        for(i=1;i<=(mulL-L);i++)
            printf(" ");
        for(i=1;i<=L;i++)
            printf("-");
        printf("\n");

        j=0;
        for(i=yL-1;i>=0;i--)
        {
            for(k=1;k<=(mulL-j-xL);k++)
                printf(" ");
            if(y[i]=='0')
            {
                for(k=1;k<=xL;k++)
                    printf("0");
                printf("\n");
            }
            else
                printf("%s\n",x);
            j++;
        }
        for(i=1;i<=mulL;i++)
            printf("-");
        printf("\n");
        for(i=mulL-1;i>=0;i--)
            printf("%c",mul[i]);
        printf("\n");
        cas++;
    }
    return 0;
}
