//Accepted

#include<stdio.h>
#include<string.h>
#include<math.h>
int hex2deci(char *hex)
{
    int i,p=0,deci=0,L,d;
    L=strlen(hex);
    for(i=L-1;i>=0;i--)
    {
        if(hex[i]>='A')
            d=hex[i]-55;
        else d=hex[i]-'0';
        deci=deci+d*pow(16,p);
        p++;
    }
    return deci;
}
void deci2bin(long deci,char *b)
{
    long int rem,p=1,i=0,bin;
    while(deci>=0)
    {
        b[i]=deci%2+'0';
        deci=deci/2;
        i++;
        if(deci==0)
            break;
    }
    b[i]='\0';
}
int main()
{
    freopen("446.txt", "r", stdin);
    char hex1[500],hex2[500], op[5],bin1[500],bin2[500],num1[500],num2[500];
    long int deci1,deci2,ans,n,L1,L2,i;
    scanf("%ld",&n);
    while(n--)
    {
        scanf("%s%s%s",hex1,op,hex2);
        deci1=hex2deci(hex1);
        deci2=hex2deci(hex2);

        if(op[0]=='+')
            ans=deci1+deci2;
        else
            ans=deci1-deci2;
        deci2bin(deci1,bin1);
        deci2bin(deci2,bin2);
        L1=strlen(bin1);
        L2=strlen(bin2);

        for(i=0;i<L1;i++)
        {
            num1[i]=bin1[L1-1-i];
        }
        num1[L1]='\0';

        for(i=0;i<L2;i++)
        {
            num2[i]=bin2[L2-1-i];
        }
        num2[L2]='\0';
        for(i=1;i<=13-L1;i++)
            printf("0");
        printf("%s %s ",num1,op);
        for(i=1;i<=13-L2;i++)
            printf("0");
        printf("%s = %ld\n",num2,ans);
    }
    return 0;
}
