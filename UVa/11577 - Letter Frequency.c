//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("11577.txt", "r", stdin);
    int t,i,len,f[30],max,p;
    char str[550];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(str);
        len=strlen(str);
        for(i=0;i<=25;i++)
            f[i]=0;
        max=0;
        for(i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                p=str[i]-'a';
                f[p]++;
            }
            else if(str[i]>='A'&&str[i]<='Z')
            {
                p=str[i]-'A';
                f[p]++;
            }
        }
        for(i=0;i<=25;i++)
        {
            if(f[i]>max)
                max=f[i];

        }
        for(i=0;i<=25;i++)
        {
            if(f[i]==max)
                printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}
