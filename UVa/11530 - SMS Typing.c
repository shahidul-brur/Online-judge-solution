//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("11530.txt", "r", stdin);
    int t, i,j,count,len;
    char sms[110];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        count=0;
        gets(sms);
        len=strlen(sms);
        for(j=0;j<len;j++)
        {
            if(sms[j]=='a' || sms[j]=='d' || sms[j]=='j' || sms[j]=='g' || sms[j]=='m' || sms[j]=='p' || sms[j]=='t' || sms[j]=='w' || sms[j]==' ')
                count+=1;
            else if(sms[j]=='b'||sms[j]=='e'||sms[j]=='h'||sms[j]=='k'||sms[j]=='n'||sms[j]=='q'||sms[j]=='u'||sms[j]=='x')
                count+=2;
            else if(sms[j]=='c'||sms[j]=='f'||sms[j]=='i'||sms[j]=='l'||sms[j]=='o'||sms[j]=='r'||sms[j]=='v'||sms[j]=='y')
                count+=3;
            else if(sms[j]=='s'||sms[j]=='z')
                count+=4;

        }
        printf("Case #%d: %d\n",i,count);
    }
    return 0;
}
