//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("644.txt", "r", stdin);
    int Y, cas=1, i, len, j, k, len1, len2;
    char num[12][15], tmp[15], check[15];
    while(gets(num[0]))
    {
        i=1;
        while(gets(num[i]))
        {
            if(num[i][0]=='9')
                break;
            i++;
        }
        for(j=0;j<i;j++)
        {
            for(k=0;k<i-1;k++)
            {
                len1=strlen(num[k]);
                len2=strlen(num[k+1]);
                if(len1>len2)
                {
                    strcpy(tmp, num[k]);
                    strcpy(num[k], num[k+1]);
                    strcpy(num[k+1], tmp);
                }
            }
        }
        Y=1;
        for(j=0;j<i-1;j++)
        {
            len1=strlen(num[j]);
            for(k=j+1;k<i;k++)
            {
                strcpy(tmp, num[k]);
                tmp[len1]='\0';
                if(strcmp(num[j], tmp)==0)
                {
                    Y=0;
                    break;
                }
            }
            if(Y==0)
                break;
        }
        if(Y==1)
            printf("Set %d is immediately decodable\n", cas);
        else if(Y==0)
            printf("Set %d is not immediately decodable\n", cas);
        cas++;

    }
    return 0;
}
