//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11878.txt", "r", stdin);
    int a,b,c,cnt=0,i,len;
    char op, qu[100],sign;
    while(scanf("%s",&qu)!=EOF)
    {
        len=strlen(qu);
        if(qu[len-1]!='?')
        {
            sign='+';
            a=b=c=0;
            for(i=0;(qu[i]!='+'&&qu[i]!='-');i++)
            {
                a=a*10+qu[i]-'0';
            }
            op=qu[i];
            for(i=i+1;qu[i]!='=';i++)
            {
                b=b*10+qu[i]-'0';
            }
            if(qu[i+1]=='-')
            {
                sign='-';
                i++;
            }
            for(i=i+1;i<len;i++)
            {
                c=c*10+qu[i]-'0';
            }
            if(sign=='-')
                c=0-c;
            if(op=='+' && (a+b)==c)
                cnt++;
            else if(op=='-' && (a-b)==c)
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
