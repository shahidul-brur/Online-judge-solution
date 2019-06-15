//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("490.txt","r",stdin);
    char str[505][505];
    int s=0,c,L,i,j,max=0;
    while(gets(str[s]))
    {
        if(strlen(str[s])>max)
            max=strlen(str[s]);
        s++;
    }
    s=s-1;

    for(c=0;c<max;c++)
    {
        for(j=s;j>=0;j--)
        {
            if(str[j][c]<='\0')
                str[j][c]=' ';
            printf("%c",str[j][c]);
        }
        printf("\n");
    }
    return 0;
}
