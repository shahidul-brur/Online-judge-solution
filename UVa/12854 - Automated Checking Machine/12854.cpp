//Accepted

#include <stdio.h>
int main()
{
    int i, c, f[8], s[8];
    while(scanf("%d %d %d %d %d",&f[1],&f[2],&f[3],&f[4],&f[5])!=EOF)
    {
        scanf("%d %d %d %d %d",&s[1],&s[2],&s[3],&s[4],&s[5]);
        c=1;
        for(i=1;i<=5;i++)
            if(f[i]==s[i])
            {
                c=0;
                break;
            }
        if(c==1)
            printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
