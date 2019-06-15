//Accepted

#include<stdio.h>
int main()
{
    //freopen("1192.txt", "r", stdin);
    int m,n,i,len,from,to;
    char str[110];
    while(scanf("%d",&m) && m!=0)
    {
        scanf("%s",&str);
        len=strlen(str);
        n=len/m;
        from=n-1;
        to=i=0;
        while(from<len)
        {
            for(from=from;from>=to;from--)
            {
                printf("%c",str[from]);
                i++;
            }
            from=i+n-1;
            to=n+to;
        }
        printf("\n");
    }
    return 0;
}
