#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11946.txt", "r", stdin);
    int t,len,i,j;
    char sms[40000];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        while(gets(sms))
        {
            len=strlen(sms);
            for(j=0;j<len;j++)
            {
                if(sms[j]=='0')
                    sms[j]='O';
                if(sms[j]=='1')
                    sms[j]='I';
                if(sms[j]=='2')
                    sms[j]='Z';
                if(sms[j]=='3')
                    sms[j]='E';
                if(sms[j]=='4')
                    sms[j]='A';
                if(sms[j]=='5')
                    sms[j]='S';
                if(sms[j]=='6')
                    sms[j]='G';
                if(sms[j]=='7')
                    sms[j]='T';
                if(sms[j]=='8')
                    sms[j]='B';
                if(sms[j]=='9')
                    sms[j]='P';

            }
          puts(sms);
        }
    }
    return 0;
}
