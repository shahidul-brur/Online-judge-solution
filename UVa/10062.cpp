//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("10062.txt", "r", stdin);
    int cas=1, freq[130], sorting[130], i, len, j, temp;
    char str[1005];
    while(gets(str))
    {
        len=strlen(str);
        memset(freq, 0, sizeof(freq));
        for(i=0, j=129;i<130;i++, j--)
        {
            sorting[i]=j;
        }
        for(i=0;i<len;i++)
        {
            freq[str[i]]++;
        }
        for(i=0;i<130;i++)
        {
            for(j=0;j<130-1;j++)
            {
                if(freq[sorting[j]]>freq[sorting[j+1]])
                {
                    temp=sorting[j];
                    sorting[j]=sorting[j+1];
                    sorting[j+1]=temp;
                }
            }
        }
        if(cas>1)
            printf("\n");
        for(i=0;i<130;i++)
        {
            if(freq[sorting[i]]!=0)
                printf("%d %d\n", sorting[i], freq[sorting[i]]);
        }
        cas++;
    }
    return 0;
}
