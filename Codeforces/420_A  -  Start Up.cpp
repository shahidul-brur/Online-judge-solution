#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j=0,k,cmp=0;
    char str[100000];
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if((str[i]=='A')||(str[i]=='H')||(str[i]=='I')||(str[i]=='M')||(str[i]=='O')||(str[i]=='T')||(str[i]=='U')||(str[i]=='V')||(str[i]=='W')||(str[i]=='X')||(str[i]=='Y'))
            j++;
    }
    if(j!=n) printf("NO\n");
    else
    {
        for(k=0;k<n;k++)
        {
          if(str[k]==str[n-k-1])
          cmp++;
        }
        if(cmp==n)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}