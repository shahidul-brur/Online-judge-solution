//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000], out[100000];
    int i,j=0,len,k=0,l;
    while(gets(str))
    {
        k=j=i=0;
        len=strlen(str);
     while(k<=len-1)
      {
        j=0;
        for(i=k;i<len;i++)
        {
            if(str[i]!=' ')
            {
                out[j]=str[i];
                j++;
            }
            else break;
        }
        for(l=j-1;l>=0;l--)
             printf("%c",out[l]);
        if(i!=len)
          printf(" ");
        k=i+1;
      }
      printf("\n");
   }
   return 0;
}

