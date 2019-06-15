//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 100
int isPallindrome(char *s)
{

    int i,len;
    char r[MAX];
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        r[i]=s[len-1-i];
    }
    r[i]='\0';
    if(strcmp(s,r)==0)
            return 1;
    return 0;
}
int isMirrored(char *ch)
{
    char temp[MAX];
    char rev[MAX];
    int len,i;
    len=strlen(ch);
    for(i=0;i<len;i++)
    {
        if(ch[i]=='E')
            temp[i]='3';
        else if(ch[i]=='3')
            temp[i]='E';

        else if(ch[i]=='J')
            temp[i]='L';
        else if(ch[i]=='L')
            temp[i]='J';

        else if(ch[i]=='S')
            temp[i]='2';
        else if(ch[i]=='2')
            temp[i]='S';

        else if(ch[i]=='Z')
            temp[i]='5';
        else if(ch[i]=='5')
            temp[i]='Z';

        else if(ch[i]=='0')
        {
            temp[i]='O';
        }
        else if(ch[i]=='B'||ch[i]=='C'||ch[i]=='D'||ch[i]=='F'||ch[i]=='G'||ch[i]=='K'||ch[i]=='N'||ch[i]=='P'||ch[i]=='Q'||ch[i]=='R'||ch[i]=='4'||ch[i]=='6'||ch[i]=='7'||ch[i]=='9')
            temp[i]=' ';
        else temp[i]=ch[i];
     }
     temp[i]='\0';
     for(i=0;i<len;i++)
        rev[i]=temp[len-1-i];
     rev[i]='\0';
     if(strcmp(rev,ch)==0)
            return 1;
    return 0;
}
int main()
{
    //freopen("401.txt", "r", stdin);
    char str[MAX];
    while(gets(str))
    {
        if(isPallindrome(str)==0 && isMirrored(str)==0)
            printf("%s -- is not a palindrome.\n",str);
        else if(isPallindrome(str)==1 && isMirrored(str)==0)
            printf("%s -- is a regular palindrome.\n",str);
        else if(isPallindrome(str)==0 && isMirrored(str)==1)
            printf("%s -- is a mirrored string.\n",str);
        else if(isPallindrome(str)==1 && isMirrored(str)==1)
            printf("%s -- is a mirrored palindrome.\n",str);
        printf("\n");
    }
    return 0;
}
