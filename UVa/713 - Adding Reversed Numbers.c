//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 220
void bigSum(char *fst, char *snd,char *rslt)
{
    int f,s,sum,carry=0,i;
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
}
int main()
{
    char a[MAX],b[MAX],sum[MAX];
    int t,len,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&a);
        scanf("%s",&b);
        bigSum(a,b,sum);
        len=strlen(sum);
        for(i=0;sum[i]=='0';i++);
        for(;i<len;i++)
            printf("%c",sum[i]);
        printf("\n");
    }
    return 0;
}
