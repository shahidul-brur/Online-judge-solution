//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 120
void rev(char *from, char *to)
{
    int i,len;
    len=strlen(from);
    for(i=0;i<len;i++)
    {
        to[i]=from[len-1-i];
    }
    to[i]='\0';
}

void bigSum(char *fir, char *sec,char *res)
{
    char fst[MAX],snd[MAX],rslt[MAX];
    int carry=0,f,s,i,sum;
    rev(fir,fst);
    rev(sec,snd);
    f=strlen(fst);
    s=strlen(snd);
    for(i=0;(i<f && i<s);i++)
    {
        sum=(fst[i]-'0') + (snd[i]-'0') + carry;
        rslt[i]=sum%10+'0';
        carry=sum/10;
    }
    for(;i<f;i++)
    {
        sum=(fst[i]-'0')+ carry;
        rslt[i]=sum%10+'0';
        carry=sum/10;
    }
    for(;i<s;i++)
    {
        sum=(snd[i]-'0')+ carry;
        rslt[i]=sum%10+'0';
        carry=sum/10;
    }
    if(carry>0)
        rslt[i++]=carry+'0';
    rslt[i]='\0';
    if(strlen(rslt)==0)
        strcpy(rslt,"0");
    rev(rslt,res);
}
int main()
{
    freopen("424.txt", "r", stdin);
    char ans[MAX]="0";
    char num[MAX];
    while(scanf("%s",&num)!=EOF)
    {
        if(strcmp(num,"0")==0)
            break;
        bigSum(ans,num,ans);
    }
    puts(ans);
    return 0;
}
