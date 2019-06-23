#include<stdio.h>
#include<string.h>
int main()
{
    int n, i,j=0,k=0,sx=0,bx=0,cn,cng;
    char str[200];
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%c",&str[i]);
        if(str[i]=='X') bx++;
        if(str[i]=='x') sx++;
    }
    if(bx>sx)
    {
        cng=n/2-sx;
        cn=cng;
        while(cng!=0)
        {
            if(str[j]=='X')
            {
                str[j]='x';
                cng--;
            }
            j++;
        }
        printf("%d",cn);
        for(i=0;i<=n;i++)
        {
            printf("%c",str[i]);
        }
    }
    if(sx>bx)
    {
        cng=n/2-bx;
        cn=cng;
        while(cng!=0)
        {
            if(str[k]=='x')
            {
                str[k]='X';
                cng--;
            }
            k++;
        }
        printf("%d",cn);
        for(i=0;i<=n;i++)
        {
            printf("%c",str[i]);
        }
    }
    if(sx==bx)
    {
        cng=0;
        cn=cng;
        printf("%d",cn);
        for(i=0;i<=n;i++)
        {
            printf("%c",str[i]);
        }
    }
    return 0;

}