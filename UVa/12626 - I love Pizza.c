//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("12626.txt", "r", stdin);
    int test,i,len,m,a,r,g,min,j,k,t;
    char str[650];
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        min=688;
        m=a=r=g=i=t=0;
        gets(str);
        len=strlen(str);
        for(j=0;j<len;j++)
        {
            if(str[j]=='M')
                m++;
            else if(str[j]=='A')
                a++;
            else if(str[j]=='R')
                r++;
            else if(str[j]=='G')
                g++;
            else if(str[j]=='I')
                i++;
            else if(str[j]=='T')
                t++;

        }
        a=a/3;
        r=r/2;
        if(a<min)
            min=a;
        if(r<min)
            min=r;
        if(m<min)
            min=m;
        if(g<min)
            min=g;
        if(t<min)
            min=t;
        if(i<min)
            min=i;
        printf("%d\n",min);
    }
    return 0;
}
