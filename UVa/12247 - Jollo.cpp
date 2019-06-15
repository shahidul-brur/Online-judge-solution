//Accepted

#include<stdio.h>
int main()
{
    //freopen("12247.txt", "r", stdin);
    int a,b,c,x,y,mini,maxi,medi,z;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&x,&y)!=EOF)
    {
        if(a==0&&b==0&&c==0&&x==0&&y==0)
            break;


        if(a>b && a>c)
            maxi=a;
        else if(b>a && b>c)
            maxi=b;
        else if(c>a && c>b)
            maxi=c;


        if(a<b && a<c)
            mini=a;
        else if(b<a && b<c)
            mini=b;
        else if(c<a && c<b)
            mini=c;


        if((a>b && a<c)||(a<b && a>c))
            medi=a;
        else if((b>a && b<c)||(b<a && b>c))
            medi=b;
        else if((c>b && c<a)||(c<b && c>a))
            medi=c;

        if((x<maxi && y<medi)||(y<maxi && x<medi))
            z=-1;
        else if(x>maxi && y>maxi)
            z=1;
        else if(x>medi && y>medi)
            z=medi+1;
        else if((x>maxi && y<medi)||(y>maxi && x<medi))
            z=maxi+1;
        while(z==a||z==b||z==c||z==x||z==y)
            z++;
        if(z>=1&&z<=52)
            printf("%d\n",z);
        else
            printf("-1\n");
    }
    return 0;
}
