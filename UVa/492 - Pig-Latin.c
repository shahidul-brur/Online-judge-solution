//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("492.txt", "r", stdin);
    int len, i,j,k,l;
    char str[1999999], r;
    while(gets(str))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]<'A' || str[i]>'z' || (str[i]>'Z' && str[i]<'a'))
               printf("%c",str[i]);
            else if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='I'||str[i]=='O'||str[i]=='E'||str[i]=='U')
            {
                printf("%c",str[i]);
                j=i+1;
                while((str[j]>='a' && str[j]<='z')||(str[j]>='A' && str[j]<='Z'))
                {
                    printf("%c",str[j]);
                    j++;
                }
                printf("ay");
                i=j-1;
            }
            else if((str[i]>='b'&&str[i]<='d')||(str[i]>='f'&&str[i]<='h')||(str[i]>='j'&&str[i]<='n')||(str[i]>='p'&&str[i]<='t')||(str[i]>='v'&&str[i]<='z')||(str[i]>='B'&&str[i]<='D')||(str[i]>='F'&&str[i]<='H')||(str[i]>='J'&&str[i]<='N')||(str[i]>='P'&&str[i]<='T')||(str[i]>='V'&&str[i]<='Z'))
            {
                r=str[i];
                j=i+1;
                while((str[j]>='a' && str[j]<='z')||(str[j]>='A' && str[j]<='Z'))
                {
                    printf("%c",str[j]);
                    j++;
                }
                printf("%c",r);
                printf("ay");
                i=j-1;
            }
        }
        printf("\n");
    }
    return 0;
}
