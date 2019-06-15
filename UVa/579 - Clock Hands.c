//Accepted

#include<stdio.h>
int main()
{
    int h,m;
    float H,M,temp,d1,d2,ans;
    while(scanf("%d:%d",&h,&m) && (h!=0 || m!=0))
    {
        H=(float)(h*5+(float)m/12);
        M=(float)m;

        if(H>M)
           d1=H-M;
        else d1=M-H;

        if(H<M)
            d2=H+60-M;
        else if(M<H)
            d2=M+60-H;

        if(d1<d2)
            ans=d1*6;
        else ans=d2*6;

        printf("%.3f\n",ans);
    }
    return 0;
}
