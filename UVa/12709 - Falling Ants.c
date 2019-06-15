//Accepted

#include<stdio.h>
int main()
{
    freopen("12709.txt", "r", stdin);
    int l,w,h,t,i,mxh=0,v,mv=0,mxv=0;
    while(scanf("%d",&t) && t!=0)
    {
        mxh=0;
        mxv=0;
        for(i=0;i<t;i++)
        {
            scanf("%d %d %d",&l,&w,&h);
            v=l*w*h;
            if(h>mxh)
            {
                mxh=h;
                mxv=v;
            }
            else if(h==mxh)
            {
              if(v>=mxv)
                mxv=v;
            }
        }
        printf("%d\n",mxv);
    }
    return 0;
}
