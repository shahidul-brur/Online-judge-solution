//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("11956.txt", "r", stdin);
    int t, cas, i, len, p, value[102];
    char ins[100005];
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s", ins);
        len=strlen(ins);
        memset(value, 0, sizeof(value));
        p=0;
        for(i=0;i<len;i++)
        {
            if(value[p]<0)
                value[p]=255;
            if(value[p]>255)
                value[p]=0;
            if(p<0)
                p=99;
            if(p>99)
                p=0;
            if(ins[i]=='<')
                p--;
            else if(ins[i]=='>')
                p++;
            if(p<0)
                p=99;
            if(p>99)
                p=0;
            if(ins[i]=='+')
                value[p]++;
            else if(ins[i]=='-')
                value[p]--;
            if(value[p]<0)
                value[p]=255;
            if(value[p]>255)
                value[p]=0;
        }
        printf("Case %d:", cas);
        for(i=0;i<100;i++)
        {
            printf(" %02X", value[i]);
        }
        printf("\n");
    }
    return 0;
}
