//Accepted
#include<stdio.h>
#include<string.h>
#define MAX 5000
long Div(char *n,long d, char *result)
{
    long long r=0,len,i,k;
    char res[5000];
    len=strlen(n);
    for(i=0;i<len;i++)
    {
        r=r*10+(n[i]-'0');
        res[i]=r/d+'0';
        r=r%d;
    }
    res[i]='\0';
    for(i=0;res[i]=='0';i++);

    strcpy(result, &res[i]);
    if(strlen(result)==0)
        strcpy(result, "0");
    return r;
}
void rev(char *from,char *to)
{
    long d;
    long len=strlen(from);
    for(d=0;d<len;d++)
        to[d]=from[len-1-d];
    to[len]='\0';
}
void add(char *fr,char *sc, char *r)
{
    char fs[MAX], sn[MAX],Rs[MAX];
    long f,s,sum,carry,i,j;
    f=strlen(fr);
    s=strlen(sc);
    rev(fr,fs);
    rev(sc,sn);
    carry=0;
    for(i=0;(i<f&&i<s);i++)
    {
        sum=(fs[i] - '0') + (sn[i] - '0') + carry;
        Rs[i]=sum%10 + '0';
        carry=sum/10;
    }
    for(;i<f;i++)
    {
        sum=fs[i]-'0' + carry;
        Rs[i]=sum%10 + '0';
        carry=sum/10;
    }
    for(;i<s;i++)
    {
        sum=sn[i]-'0' + carry;
        Rs[i]=sum%10 + '0';
        carry=sum/10;
    }
    if(carry>0)
        Rs[i++]=carry + '0';
    Rs[i]='\0';
    if(strlen(Rs)==0)
        strcpy(Rs,"0");
    rev(Rs,r);
}
int main()
{
    freopen("10925.txt", "r", stdin);
    long n,f,i,c=1,j;
    char v[5000],result[5000],p[5000];
    while(scanf("%ld %ld",&n,&f)==2)
    {
        if(n==0 && f==0)
            break;
        strcpy(result,"0");
        for(i=1;i<=n;i++)
        {
            scanf("%s",&v);
            add(v,result,result);
        }
        Div(result,f,p);
        printf("Bill #%d costs %s: each friend should pay %s\n\n",c,result,p);
        c++;
    }
    return 0;
}

