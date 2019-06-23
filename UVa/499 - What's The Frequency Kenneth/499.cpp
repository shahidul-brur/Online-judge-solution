//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("499.txt", "r", stdin);
    int cap[27], small[27], i, len, maxi;
    char str[1005];
    while(gets(str))
    {
        len=strlen(str);
        memset(cap, 0, sizeof(cap));
        memset(small, 0, sizeof(small));
        maxi=0;
        for(i=0;i<len;i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                cap[str[i]-'A']++;
            }
            else if(str[i]>='a' && str[i]<='z')
            {
                small[str[i]-'a']++;
            }
        }

        for(i=0;i<26;i++)
        {
            if(cap[i]>maxi)
                maxi=cap[i];

        }

        for(i=0;i<26;i++)
        {
            if(small[i]>maxi)
                maxi=small[i];
        }

        for(i=0;i<26;i++)
        {
            if(cap[i]==maxi)
                printf("%c", i+'A');

        }

        for(i=0;i<26;i++)
        {
            if(small[i]==maxi)
                printf("%c", i+'a');
        }
        printf(" %d\n", maxi);
    }
    return 0;
}
