//Accepted

#include<stdio.h>
#include<string.h>
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
int main()
{
    freopen("10494.txt", "r", stdin);
    long b,rem;
    char sign,num[5000],result[5000],l,j;
    while(scanf("%s %c %ld",&num,&sign,&b)!=EOF)
    {
        rem=Div(num,b,result);
        l=strlen(result);
        if(sign=='/')
        {
            puts(result);
        }
        else
            printf("%ld\n",rem);

    }
    return 0;
}
