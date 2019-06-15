#include<stdio.h>
#include<string.h>
#define MAX 9999999
void rev(char *from, char *to)
{
    int i,len;
    len=strlen(from);
    for(i=0;i<len;i++)
    {
        to[i]=from[len-1-i];
    }
    to[len]='\0';
}
void mult(char *fir, char *sec, char *ans)
{
    char F[MAX], S[MAX], res[MAX];
    int mul,i,j,last,f,s,hold;
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
    //freopen("10106.txt", "r", stdin);
    int L,p;
    char num[MAX],result[MAX];
    while(scanf("%s",&num)==1)
    {
        mult(num,num,result);
        L=strlen(result);
        for(p=0;p<L;p++)
            printf("%c",result[p]);
        printf("\n");
    }
    return 0;
}
