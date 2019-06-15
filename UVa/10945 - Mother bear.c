//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10945.txt", "r", stdin);
    int len,i,j,l;
    char sen[99999],rev[99999];
    while(gets(sen))
    {
        if(strcmp(sen, "DONE")==0)
            break;
        len=strlen(sen);
        for(i=j=0;sen[i]!='\0';i++)
        {
            if(sen[i]>='a' && sen[i]<='z')
            {
                sen[j++]=sen[i];
            }
            else if(sen[i]>='A' && sen[i]<='Z')
            {
                sen[j++]=sen[i]+32;
            }
        }
        sen[j]='\0';
        len=strlen(sen);
        l=len-1;
        for(i=0;i<=len-1;i++)
        {
            rev[l]=sen[i];
            l--;
        }
        rev[len]='\0';
        if(strcmp(sen, rev)==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
