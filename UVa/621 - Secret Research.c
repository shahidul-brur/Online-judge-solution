//Accepted

#include<stdio.h>
int main()
{
    //freopen("621.txt", "r", stdin);
    long long int c,n,t,len;
    char str[99999];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",&str);
        len=strlen(str);
        if(len==1 && (str[0]=='1' || str[0]=='4'))
            printf("+\n");
        else if(len==2 && str[len-1]=='8' && str[len-2]=='7')
            printf("+\n");
        else if(len>2 && str[len-1]=='5' && str[len-2]=='3')
            printf("-\n");
        else if(len>2 && str[0]=='9' && str[len-1]=='4')
            printf("*\n");
        else if(len>2 && str[0]=='1' && str[1]=='9' && str[2]=='0')
            printf("?\n");
    }
    return 0;
}
