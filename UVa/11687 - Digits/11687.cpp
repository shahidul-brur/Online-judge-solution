#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("11687.txt", "r", stdin);
    int digits[50000], i, ans, len, brk, d, dgt;
    char num[1000009];
    while(gets(num))
    {
        if(strcmp(num, "END")==0)
            break;
        brk=0;
        len=strlen(num);
        digits[1]=len;
        if(num[0]=='1' && num[1]=='\0')
        {
            ans=1;
            brk=1;
        }
        for(i=2;brk==0;i++)
        {
            d=digits[i-1];
            dgt=0;
            while(d>0)
            {
                dgt++;
                d/=10;
            }
            digits[i]=dgt;
            if(digits[i]==digits[i-1])
            {
                ans=i;
                brk=1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
