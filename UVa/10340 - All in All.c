//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10340.txt", "r", stdin);
    char subs[1039999],mains[1039999],ch;
    long long int i,j,val,k;
    while(scanf("%s %s",&subs,&mains) !=EOF)
    {
        if(strlen(subs)>strlen(mains))
            printf("No\n");
        else
        {
            j=val=0;
            for(i=0;i<strlen(subs);i++)
            {
                ch=subs[i];
                for(j=j;j<strlen(mains);j++)
                {
                    if(ch==mains[j])
                    {
                        val++;
                        j++;
                        break;
                    }
                }
            }
            if(val==strlen(subs))
                printf("Yes\n");
            else printf("No\n");
        }

    }
    return 0;
}
