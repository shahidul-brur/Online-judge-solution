//ACCEPTED

#include<stdio.h>
#include<string.h>
void rev(char *from, char *to)
{
    long i;
    long len=strlen(from);
    for(i=0;i<len;i++)
        to[i]=from[len-1-i];
    to[len]='\0';
}
void bigSum(char *fir, char *sec,char *res)
{
    char F[5010],S[5010],R[11000];
    long f,s,sum,i,j,carry;
    f=strlen(fir);
    s=strlen(sec);
    rev(fir,F);
    rev(sec,S);
    carry=0;
    for(i=0;(i<f&&i<s);i++)
    {
        sum=(F[i]-'0')+(S[i]-'0')+carry;
        R[i]=sum%10+'0';
        carry=sum/10;
    }
    for(;i<f;i++)
    {
        sum=F[i]-'0'+carry;
        R[i]=sum%10+'0';
        carry=sum/10;
    }
    for(;i<s;i++)
    {
        sum=S[i]-'0'+carry;
        R[i]=sum%10+'0';
        carry=sum/10;
    }
    if(carry>0)
        R[i++]=carry+'0';
    R[i]='\0';
    rev(R,res);
}
char fib[5010][11000];
int main()
{

    long n,L,m,k;

    fib[0][0]='0';
    fib[1][0]='1';
    for(k=2;k<=5001;k++)
    {
        bigSum(fib[k-2],fib[k-1],fib[k]);
    }
    while(scanf("%ld",&n)!=EOF)
    {
        L=strlen(fib[n]);
        printf("The Fibonacci number for %ld is ",n);
        for(m=0;m<L;m++)
            printf("%c",fib[n][m]);
        printf("\n");
    }
    return 0;
}
