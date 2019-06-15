#include<stdio.h>
#include<string.h>
void rev(char *from, char *to)
{
    int i;
    int len=strlen(from);
    for(i=0;i<len;i++)
        to[i]=from[len-1-i];
    to[len]='\0';
}
void bigSum(char *fir, char *sec,char *res)
{
    char F[110],S[110],R[110];
    int f,s,sum,i,j,carry;
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
    for(;i<=100;i++)
        R[i]='0';
    R[i]='\0';
    rev(R,res);
}
char fib[505][110];
int main()
{
    freopen("10183.txt", "r", stdin);
    int m,k,cnt,cmp,L;
    char a[110], b[110],A[110], B[110];
    fib[0][0]='0';
    fib[1][0]='1';
    for(k=2;k<=501;k++)
    {
        bigSum(fib[k-2],fib[k-1],fib[k]);
    }
    while(scanf("%s %s", a, b)!=EOF)
    {
        if(a[0]=='0' && b[0]=='0')
            break;

        rev(a, A);
        L=strlen(A);
        for(k=L;k<=100;k++)
            A[k]='0';
        A[k]='\0';
        rev(A, a);

        rev(b, B);
        L=strlen(B);
        for(k=L;k<=100;k++)
            B[k]='0';
        B[k]='\0';
        rev(B, b);

        k=1;
        cnt=0;
        while(strcmp(fib[k], a)<0)
        {
            printf("%s %s\n", a, fib[k]);
            k++;
        }
        printf("\n");
        while(strcmp(b, fib[k])>=0)
        {
            printf("%s %s\n",fib[k], b);
            k++;
            cnt++;
        }
        printf("\n%d\n", cnt);

    }
    return 0;
}
