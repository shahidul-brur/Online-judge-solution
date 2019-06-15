//Accepted

#include <stdio.h>
#include<string.h>
int main()
{
    //freopen("10679.txt", "r", stdin);
    int t,q,i,j,k,len,Y,m,L;
    char ms[100099], ss[1099],p[1099];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&ms);
        scanf("%d",&q);
        len=strlen(ms);
        while(q--)
        {
            scanf("%s",&ss);
            L=strlen(ss);
            for(i=0;i<L;i++)
                p[i]=ms[i];
            p[i]='\0';
            if(strcmp(ss,p)==0)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
