//Accepted

#include<stdio.h>
#include<string.h>
struct words
{
    char words_in_lines[1200];
};
int main()
{
    freopen("11220.txt", "r", stdin);
    int t,i,j,k,l,c;
    char str[10000],ch[20];
    struct words wr[1000];
    scanf("%d",&t);
    getchar();
    gets(ch);
    for(c=1;c<=t;c++)
    {
        if(c>1)
            printf("\n");
        printf("Case #%d:\n",c);
        while(gets(str))
        {
          if(strcmp(str,"")==0)
             break;
          j=0;
          k=1;
          while(str[j]!='\0')
          {
                l=0;
                for(j=j;(str[j]!=' '||str[j]=='\0');j++)
                {
                    wr[k].words_in_lines[l]=str[j];
                    l++;
                }
                wr[k].words_in_lines[l]='\0';
                if(str[j]=='\0')
                   break;
              k++;
              j++;
          }
          j=0;
          for(i=1;i<k;i++)
          {
             if(strlen(wr[i].words_in_lines)>j)
             {
                 printf("%c",wr[i].words_in_lines[j]);
                 j++;
             }

          }
          printf("\n");
        }
    }
    return 0;
}
