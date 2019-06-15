//Accepted

#include<stdio.h>
int main()
{
    int h1,m1,h2,m2,s,e,ans;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2) && (h1!=0 || m1!=0 || h2!=0 || m2!=0))
    {
        if(h2<h1 || (h2==h1 && m2<m1))
            h2+=24;
        s=h1*60+m1;
        e=h2*60+m2;
        ans=e-s;
        printf("%d\n",ans);
    }
    return 0;
}
