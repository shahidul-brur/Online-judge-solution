//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("1584.txt", "r", stdin);
    int t, i, len, start,cnt;
    char seq[105], temp[102], smallest[105];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", seq);
        len=strlen(seq);
        strcpy(smallest, seq);
        for(start=1;start<len;start++)
        {
            for(i=start, cnt=0;cnt<len;cnt++,i++)
            {
                if(i>=len)
                    i=0;
                temp[cnt]=seq[i];
            }
            temp[len]='\0';
            if(strcmp(temp, smallest)<0)
                strcpy(smallest, temp);

        }
        printf("%s\n", smallest);
    }
    return 0;
}
