//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("494.txt", "r", stdin);
    int len,i,j,count;
    char str[999999];
    while(gets(str))
    {
        count=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
            {
                count++;
                for(j=i+1;j<len;j++)
                {
                    if((str[j]>='A' && str[j]<='Z')||(str[j]>='a' && str[j]<='z'))
                    {
                        i++;
                    }
                    else break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
