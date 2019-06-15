//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 100
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
    freopen("11115.txt", "r", stdin);
    int i,p,len;
    char num[50],temp[50],mul[50],ans[50];
    while(scanf("%s %d",&num,&p)!=EOF)
    {
        if(num[0]=='0' && p==0)
            break;
        if(p==0)
            printf("1\n");
        else{
        strcpy(temp, num);
        for(i=1;i<p;i++)
        {
            mult(temp,num,temp);
        }

        len=strlen(temp);
        for(i=0;i<len;i++)
            printf("%c",temp[i]);
        printf("\n");
        }
    }
    return 0;
}
