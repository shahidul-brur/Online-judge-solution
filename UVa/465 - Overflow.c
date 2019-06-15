//Accepted

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200000
#define M 2147483647
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
void mult(char *fir, char *sec, char *ans)
{
    char F[MAX], S[MAX], res[MAX];
    long long int mul,i,j,last,f,s,hold;
    f=strlen(fir);
    s=strlen(sec);
    rev(fir,F);
    rev(sec,S);
    last=-1;
    for(i=0;i<=f+s;i++)
        res[i]='0';
    res[i]='\0';
    for(i=0;i<s;i++)
    {
        hold=0;
        for(j=0;j<f;j++)
        {
            mul=(F[j]-'0')*(S[i]-'0')+hold+(res[i+j] - '0');
            res[i+j]=mul%10 + '0';
            hold=mul/10;
            if(i+j>last)
                last=f+s;
        }
        while(hold>0)
        {
            mul=hold+(res[i+j] - '0');
            res[i+j]=mul%10 + '0';
            hold=mul/10;
            if(i+j>last)
                last=i+j;
            j++;
        }
    }
    while(last>0 && res[last]=='0')
        last--;
    res[last+1]='\0';
    rev(res,ans);
}
int main()
{
    freopen("465.txt", "r", stdin);
    char F[MAX], S[MAX], A[MAX], op[5];
    long long flen,slen,alen,z, vf,vs,va,fb,sb,ab,l;
    while(scanf("%s%s%s",&F,&op,&S)==3)
    {
        printf("%s %s %s\n",F,op,S);
        flen=strlen(F);
        slen=strlen(S);
        fb=sb=ab=0;
        if(flen>=10)
        {
            z=0;
            while(F[z]=='0')
            {
                z++;
            }
            flen-=z;
            if(flen>10)
                fb=1;
            else if(flen==10)
            {
                vf=0;
                for(l=0;l<flen;l++)
                {
                    vf=vf*10+(F[l]-'0')%10;
                }
                if(vf>M)
                    fb=1;
            }
        }
        if(slen>=10)
        {
            z=0;
            while(S[z]=='0')
            {
                z++;
            }
            slen-=z;
            if(slen>10)
                sb=1;
            else if(slen==10)
            {
                vs=0;
                for(l=0;l<slen;l++)
                {
                    vs=vs*10+(S[l]-'0')%10;
                }
                if(vs>M)
                    sb=1;
            }
        }
        if(op[0]=='+')
            add(F,S,A);
        else
            mult(F,S,A);
        alen=strlen(A);
        if(alen>10)
                ab=1;
        else if(alen==10)
        {
            va=0;
            for(l=0;l<alen;l++)
            {
                va=va*10+(A[l]-'0')%10;
            }
            if(va>M)
                ab=1;
        }
        if(fb==1)
            printf("first number too big\n");
        if(sb==1)
            printf("second number too big\n");
        if(ab==1)
            printf("result too big\n");
    }
    return 0;
}
