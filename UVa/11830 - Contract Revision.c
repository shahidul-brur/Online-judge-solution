//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("11830.txt", "r", stdin);
    int i,j,len;
    char d, num[120];
    while(scanf("%c",&d)!=EOF)
    {
        getchar();
        gets(num);
        if(d=='0' && num[0]=='0')
            break;
        for(i=j=0;num[i]=='0',num[i]!='\0';i++)
        {
            if(num[i]!=d)
                num[j++]=num[i];
        }
        num[j]='\0';
        if(strcmp(num, "")!=0)
        {
           i=0;
           len=strlen(num);
           if(num[0]=='0')
           {
              while(num[i]=='0')
               {
                   if(i==len-1)
                      break;
                  i++;
               }
           }
           for(i=i;i<len;i++)
            {
                printf("%c",num[i]);
            }
             printf("\n");
           }
        else
            printf("0\n");
    }
    return 0;
}
