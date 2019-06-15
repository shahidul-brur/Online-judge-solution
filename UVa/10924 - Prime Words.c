//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    int len,n,i,j,prime,r;
    char str[50];
    while(scanf("%s",&str)!=EOF)
    {
        prime=1;
        n=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                n+=1+str[i]-'a';
            }
            else if(str[i]>='A' && str[i]<='Z')
            {
                n+=27+str[i]-'A';
            }
        }
        r=sqrt(n);
        for(i=2;i<=r;i++)
        {
            if(n%i==0)
            {
                prime=0;
                break;
            }
        }
        if(prime==1)
            printf("It is a prime word.\n");
        else if(prime==0)
            printf("It is not a prime word.\n");
    }
    return 0;
}
