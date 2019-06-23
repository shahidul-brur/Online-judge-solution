//Accepted

#include <stdio.h>
#include <string.h>

int main()
{
    freopen("455.txt", "r", stdin);
    int t, c=1, len, period, i, j, br;
    char str[100], mean[100], sub[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        len=strlen(str);
        for(period=1;period<=len;period++)
        {

            if(len%period==0)
            {
                br=0;
                strcpy(mean, str);
                mean[period]='\0';
                for(j=0;j<period;j++)
                {
                    for(i=j+period;i<len;i+=period)
                    {
                        if(str[i]!=mean[j])
                           {
                               br=1;
                               break;
                           }
                    }
                    if(br==1)
                        break;
                }

            }
            if(br==0)
                break;
        }
        if(c>1)
            printf("\n");
        printf("%d\n",period);
        c++;
    }
    return 0;
}
