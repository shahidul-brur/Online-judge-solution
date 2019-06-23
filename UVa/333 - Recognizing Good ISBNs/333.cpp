//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("333.txt", "r", stdin);
    int len, i, s1[12], sum, total, Y, start, last, c, digits;
    char isbn[200];
    while(gets(isbn))
    {
        len=strlen(isbn);
        start=0;
        last=len-1;
        while(isbn[start]==' ')
            start++;
        while(isbn[last]==' ')
            last--;
        isbn[last+1]='\0';
        c=sum=total=digits=0;
        Y=1;
        for(i=start;i<=last;i++)
        {
            if(isbn[i]=='-');
            else if(isbn[i]=='X')
            {
                if(i!=last)
                {
                    Y=0;
                    break;
                }
                sum+=10;
                s1[c++]=sum;
                digits++;
            }
            else if(isbn[i]>='0' && isbn[i]<='9')
            {
                digits++;
                sum+=isbn[i]-'0';
                s1[c++]=sum;
            }
            else
            {
                Y=0;
                break;
            }

        }
        if(digits<10)
            Y=0;
        if(Y==1)
        {
            for(i=0;i<c;i++)
                total+=s1[i];
            if(total%11!=0)
                Y=0;
        }
        printf("%s is ",&isbn[start]);
        if(Y==1)
            printf("correct.\n");
        else
            printf("incorrect.\n");
    }
    return 0;
}
