//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("12555.txt", "r", stdin);
    char dis[500];
    int len,c,t,a,b,i;
    double w;
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++)
    {
        gets(dis);
        len=strlen(dis);
        a=0;
        b=0;
        for(i=0;(dis[i]>='0'&&dis[i]<='9');i++)
            a=a*10+(dis[i]-'0');

        for(;(dis[i]<'0'||dis[i]>'9');i++);

        for(;(i<len&&dis[i]>='0'&&dis[i]<='9');i++)
            b=b*10+(dis[i]-'0');

        w=a*0.5+b*0.05;
        printf("Case %d: %g\n",c,w);
    }
    return 0;
}
