//Accepted
#include<stdio.h>
#include<string.h>
char f[10000], fact[1010][10000];
int main()
{

    int i,j,fSum,k,div,n,len,L,m,sum;

    fact[0][0]='1';
    fact[1][0]='1';
    strcpy(f,"1");
    for(k=2;k<=1000;k++)
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
        for(j=0;j<i;j++)
            fact[k][j]=f[j];
        fact[k][j]='\0';
    }
    while(scanf("%d",&n)!=EOF)
    {
        fSum=0;
        L=strlen(fact[n]);
        for(m=L-1;m>=0;m--)
            fSum+=fact[n][m]-'0';
        printf("%d\n",fSum);
    }
    return 0;
}
