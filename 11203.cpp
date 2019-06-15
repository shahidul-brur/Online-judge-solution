//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11203.txt", "r", stdin);
    int t, i, j, cntM, cntE, whatF, whatL, whatM, len, Yes;
    char input[55];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", input);
        len=strlen(input);
        cntE=cntM=whatF=whatL=whatM=0;
        Yes=1;
        for(i=0;i<len;i++)
        {
            if(input[i]!='M' && input[i]!='E' && input[i]!='?')
            {
                Yes=0;
                break;
            }
            if(input[i]=='M')
                cntM++;
            else if(input[i]=='E')
                cntE++;
        }
        if(cntE!=1 || cntM!=1)
            Yes=0;
        if(Yes==1)
        {
            for(i=0;input[i]=='?';i++,whatF++);
            for(i=i+1;input[i]=='?';i++,whatM++);
            for(i=i+1;input[i]=='?';i++,whatL++);
            if(whatF==0 || whatM==0 || whatL==0)
                Yes=0;
            if(whatM==1 && whatF==(whatL-1));
            else
            {
                if((whatF + whatM)==whatL);
                else Yes=0;
            }

        }
        if(Yes==0)
            printf("no-theorem\n");
        else printf("theorem\n");
    }
    return 0;
}
