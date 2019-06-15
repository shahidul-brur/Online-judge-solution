//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 5000
void rev(char *from, char *to)
{
    int i,len;
    len=strlen(from);
    for(i=0;i<len;i++)
        to[i]=from[len-1-i];
    to[i]='\0';
}
void sub(char *large, char *small,char *result)
{
    char L[MAX], S[MAX], R[MAX];
    int diff, s,l,hold,i,j;
    s=strlen(small);
    l=strlen(large);
    rev(large,L);
    rev(small,S);
    for(i=s;i<l;i++)
        S[i]='0';
    S[i]='\0';
    hold=0;
    for(i=0;i<l;i++)
    {
        diff=L[i] - ( S[i] + hold );
        if(diff<0)
        {
            R[i]=10+diff+'0';
            hold=1;
        }
        else
        {
            R[i]=diff+'0';
            hold=0;
        }
    }
    for(i=l-1;i>0&&R[i]=='0';i--);
    R[i+1]='\0';
    rev(R,result);
}
long rem(char *num,long div)
{
    long r=0,L,i,d=0;
    L=strlen(num);
    for(i=0;i<L;i++)
    {
        r=(r*10+(num[i]-'0'))%div;
    }
    return r;
}
int main()
{
    //freopen("10992.txt","r",stdin);
    char y[MAX],year[MAX],sb[10];
    int c=1,flag,len,d2,d5,d7,d11,d15,d20,d28,d36,d4,d100,d400;
    strcpy(sb,"2148");
    while(scanf("%s",&y)!=EOF)
    {
        if(y[0]=='0' && y[1]=='\0')
            break;

        if(c>1)
            printf("\n");
        c++;
        printf("%s\n",y);

        len=strlen(y);
        if(len<4)
        {
            printf("No ghost will come in this year\n");
            continue;
        }
        if(len==4)
        {
            if(strcmp(sb,y)>0)
            {
                printf("No ghost will come in this year\n");
                continue;
            }
        }
        flag=1;
        sub(y,sb,year);

        d2=rem(year,2);
        d5=rem(year,5);
        d7=rem(year,7);
        d11=rem(year,11);
        d15=rem(year,15);
        d20=rem(year,20);
        d28=rem(year,28);
        d36=rem(year,36);
        d4=rem(y,4);
        d100=rem(y,100);
        d400=rem(y,400);

        if(d2==0)
        {
            printf("Ghost of Tanveer Ahsan!!!\n");
            flag=0;
        }

        if(d5==0)
        {
            printf("Ghost of Shahriar Manzoor!!!\n");
            flag=0;
        }

        if(d7==0)
        {
            printf("Ghost of Adrian Kugel!!!\n");
            flag=0;
        }

        if(d11==0)
        {
            printf("Ghost of Anton Maydell!!!\n");
            flag=0;
        }

        if(d15==0)
        {
            printf("Ghost of Derek Kisman!!!\n");
            flag=0;
        }

        if(d20==0)
        {
            printf("Ghost of Rezaul Alam Chowdhury!!!\n");
            flag=0;
        }

        if(d28==0)
        {
            printf("Ghost of Jimmy Mardell!!!\n");
            flag=0;
        }

        if(d36==0)
        {
            printf("Ghost of Monirul Hasan!!!\n");
            flag=0;
        }

        if((d400==0) || (d4==0 && d100!=0))
        {
            printf("Ghost of K. M. Iftekhar!!!\n");
            flag=0;
        }

        if(flag==1)
            printf("No ghost will come in this year\n");
    }
    return 0;
}
