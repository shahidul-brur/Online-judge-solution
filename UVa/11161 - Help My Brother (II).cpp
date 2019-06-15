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
void bigDiv(char *num, char *res)
{
    int i, j=0, L=strlen(num), d=0, rem=0;
    char Res[11000];
    for(i=0;i<L;i++)
    {
        d=rem*10 + (num[i] - '0');
        Res[j++]=d/2+'0';
        rem=d%2;
    }
    Res[j]='\0';
    strcpy(res, Res);
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
    freopen("11161.txt", "r", stdin);
    long n,L,m,k,cas=1,i;
    char R[11000], prev[11000];
    strcpy(prev, "0");
    fib[0][0]='0';
    fib[1][0]='1';
    for(k=2;k<=5001;k++)
    {
        bigSum(fib[k-2],fib[k-1],fib[k]);
    }
    char median[1505][11000];
    for(i=1;i<=1500;i++)
    {
        if(i%2==0)
            bigDiv(fib[i], R);
        else
        {
            bigSum(fib[i], "1", R);
            bigDiv(R, R);
        }
        bigSum(prev, R, median[i]);
    }
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0)
            break;
        puts(median[n]);
        cas++;
    }
    return 0;
}

