//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11787.txt", "r", stdin);
    int t, len, cnt, error, i, j, n, k, order[550],c;
    char num[550];
    scanf("%d",&t);
    while(t--)
    {
        n=0;
        scanf("%s",&num);
        len=strlen(num);
        c=1;
        for(i=0;i<len;i++)
        {
            cnt=1;
            error=0;
            j=i+1;
            while(num[i]==num[j])
            {
                cnt++;
                j++;
            }
            if(cnt>9)
                error=1;
            for(k=j+1;k<len;k++)
             {
                if(num[k]==num[i])
                {
                    error=1;
                    break;
                }
             }
            if(error==1)
                break;
            if(num[i]=='B')
            {
                n+=cnt;
                order[c]=1;
            }
            else if(num[i]=='U')
            {
                n+=cnt*10;
                order[c]=2;
            }
            else if(num[i]=='S')
            {
                n+=cnt*100;
                order[c]=3;
            }
            else if(num[i]=='P')
            {
                n+=cnt*1000;
                order[c]=4;
            }
            else if(num[i]=='F')
            {
                n+=cnt*10000;
                order[c]=5;
            }
            else if(num[i]=='T')
            {
                n+=cnt*100000;
                order[c]=6;
            }
            else if(num[i]=='M')
            {
                n+=cnt*1000000;
                order[c]=7;
            }
            c++;
            i=j-1;
        }
        if(order[2]>order[1])
        {
            for(i=3;i<c;i++)
                if(order[i]<order[i-1])
                {
                    error=1;
                    break;
                }
        }
        else if(order[2]<order[1])
        {
            for(i=3;i<c;i++)
                if(order[i]>order[i-1])
                {
                    error=1;
                    break;
                }
        }
        if(error==1)
            printf("error\n");
        else
            printf("%d\n",n);
    }

    return 0;
}
