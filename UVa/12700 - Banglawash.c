#include<stdio.h>
int main()
{
    int b,w,t,a,m,s,i,j;
    char res[15];
    scanf("%d",&s);
    for(i=1;i<=s;i++)
    {
        b=0,w=0,t=0,a=0;
        scanf("%d",&m);
        scanf("%s",res);
        for(j=0;j<m;j++)
        {
            if(res[j]=='W') w++;
            else if(res[j]=='B') b++;
            else if(res[j]=='A') a++;
            else if(res[j]=='T') t++;
        }
        if(a==m) printf("Case %d: ABANDONED\n",i);
        else
        {
            if(b==0 && (w+a)==m && t==0) printf("Case %d: WHITEWASH\n",i);
            else if(w==0 && (b+a)==m && t==0) printf("Case %d: BANGLAWASH\n",i);
            else if(b==w && b!=0) printf("Case %d: DRAW %d %d\n",i,b,t);
            else if(b>w && (b+a)!=m) printf("Case %d: BANGLADESH %d - %d\n",i,b,w);
            else if(w>b && (w+a)!=m) printf("Case %d: WWW %d - %d\n",i,w,b);
        }
    }
    return 0;
}
