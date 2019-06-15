//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11398.txt", "r", stdin);
    char num[10100], temp[250], last, bin[40];
    long long len, decimal, i, z, j, prev, b, p;
    while(gets(num))
    {
        if(num[0]=='~')
            break;
        len=strlen(num);
        last=num[len-1];
        while(last!='#')
        {
            gets(temp);
            len=strlen(temp);
            last=temp[len-1];
            temp[len]=' ';
            temp[len+1]='\0';
            strcat(num, temp);
        }
        len=strlen(num);
        if(num[len-1]=='#')
            num[len-1]='\0';
        len=strlen(num);
        if(num[len-1]==' ')
            num[len-1]='\0';
        len=strlen(num);
        decimal=b=0;
        p=1;
        for(i=0;i<len;i++)
        {
            for(j=i,z=0;num[j]!=' ' && j<len;j++)
            {
                z++;
            }
            i=j;
            if(z==1)
            {
                last='1';
                prev=1;
            }
            else if(z==2)
            {
                prev=0;
                last='0';
            }
            else if(z>2)
            {
                for(j=1;j<=(z-2);j++)
                    bin[b++]=last;
            }
        }
        bin[b]='\0';
        len=strlen(bin);
        for(i=len-1;i>=0;i--)
        {
            decimal=decimal + (bin[i]-'0')*p;
            p*=2;
        }
        printf("%lld\n", decimal);
    }
    return 0;
}
