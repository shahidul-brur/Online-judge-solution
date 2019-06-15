//Accepted
#include<stdio.h>
#include<string.h>
char f[100000], fact[10005][100000];
int main()
{

    int i,j,k,div,n,len,L,m,sum;
    char d[10005];
    d[0]=d[1]='1';
    fact[0][0]='1';
    fact[1][0]='1';
    strcpy(f,"1");
    for(k=2;k<=10001;k++)
    {
        len=strlen(f);
        div=0;
        i=0;
        while(i<len)
        {
            sum=div+(f[i]-'0')*k;
            f[i]=(sum%10)+'0';
            div=sum/10;
            i++;
        }
        while(div>0)
        {
            f[i]=(div%10) + '0';
            div=div/10;
            i++;
        }
        f[i]='\0';
        L=strlen(f);
        for(m=0;m<L;m++)
        {
            if(f[m]!='0')
            {
                d[k]=f[m];
                break;
            }
        }
    }
    while(scanf("%d",&n)!=EOF)
    {



           if(n<10)
                printf("    %d -> %c\n",n,d[n]);
           if(n>9&&n<100)
                printf("   %d -> %c\n",n,d[n]);
           if(n>99&&n<1000)
                printf("  %d -> %c\n",n,d[n]);
           if(n>999)
                printf(" %d -> %c\n",n,d[n]);
    }
    return 0;
}
