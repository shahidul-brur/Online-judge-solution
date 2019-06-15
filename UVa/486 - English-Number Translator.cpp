#include<stdio.h>
#include<string.h>
int main()
{
    freopen("486.txt", "r", stdin);
    long m,th,h,o,len,i,j,n,d,t,sign;
    char num[100], wrd[50];
    while(gets(num))
    {
        sign=0;
        m=th=h=o=t=d=0;
        len=strlen(num);
        for(i=0,j=0;i<len;i++)
        {

            if(num[i]!=' ')
                wrd[j++]=num[i];
            if(num[i]==' ' || i==len-1)
            {
                wrd[j]='\0';
                if(strcmp(wrd,"negative")==0)
                    sign=1;
                else if(strcmp(wrd,"zero")==0)
                    d=0;

                else if(strcmp(wrd,"one")==0)
                    d=d+1;

                else if(strcmp(wrd,"two")==0)
                    d=d+2;

                else if(strcmp(wrd,"three")==0)
                    d=d+3;

                else if(strcmp(wrd, "four")==0)
                    d=d+4;

                else if(strcmp(wrd, "five")==0)
                    d=d+5;

                else if(strcmp(wrd, "six")==0)
                    d=d+6;

                else if(strcmp(wrd, "seven")==0)
                    d+=7;

                else if(strcmp(wrd,"eight")==0)
                    d+=8;

                else if(strcmp(wrd, "nine")==0)
                    d+=9;

                else if(strcmp(wrd, "ten")==0)
                    d+=10;

                else if(strcmp(wrd, "eleven")==0)
                    d+=11;

                else if(strcmp(wrd, "twelve")==0)
                    d+=12;

                else if(strcmp(wrd, "thirteen")==0)
                    d+=13;

                else if(strcmp(wrd, "fourteen")==0)
                    d+=14;

                else if(strcmp(wrd, "fifteen")==0)
                    d+=15;

                else if(strcmp(wrd, "sixteen")==0)
                    d+=16;

                else if(strcmp(wrd, "seventeen")==0)
                    d+=17;

                else if(strcmp(wrd, "eighteen")==0)
                    d+=18;

                else if(strcmp(wrd, "nineteen")==0)
                    d+=19;

                else if(strcmp(wrd, "twenty")==0)
                    d+=20;

                else if(strcmp(wrd, "thirty")==0)
                    d+=30;

                else if(strcmp(wrd, "forty")==0)
                    d+=40;

                else if(strcmp(wrd, "fifty")==0)
                    d+=50;

                else if(strcmp(wrd, "sixty")==0)
                    d+=60;

                else if(strcmp(wrd, "seventy")==0)
                    d+=70;

                else if(strcmp(wrd, "eighty")==0)
                    d+=80;

                else if(strcmp(wrd, "ninety")==0)
                    d+=90;

                else if(strcmp(wrd, "hundred")==0)
                {
                    //h=d*100;
                    d=d*100;
                    //d=0;
                }
                else if(strcmp(wrd, "thousand")==0)
                {
                    //th=d*1000;
                    d=d*1000;
                    //d=0;
                }
                else if(strcmp(wrd, "million")==0)
                {
                    //m=d*1000000;
                    d=d*1000000;
                    //d=0;
                }

                j=0;
            }
        }
        o=d;
        n=m+th+h+t+o;
        if(sign==1)
            printf("-");
        printf("%ld\n",d);
    }
    return 0;
}
