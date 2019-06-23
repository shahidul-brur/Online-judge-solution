#include <stdio.h>
#define eps 1e-4
int main()
{
    freopen("191.txt", "r", stdin);
    int t, xS, yS, xE, yE, xL, yU, xR, yD, X, Y, yes, temp;
    double m, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d %d %d", &xS, &yS, &xE, &yE, &xL, &yU, &xR, &yD);
        if(xL>xR)
        {
            temp=xL;
            xL=xR;
            xR=temp;
        }
        if(yD>yU)
        {
            temp=yD;
            yD=yU;
            yU=temp;
        }
        if(xE>xS)
        {
            temp=xE;
            xE=xS;
            xS=temp;
        }
        if(yE>yS)
        {
            temp=yS;
            yS=yE;
            yE=temp;
        }
        //printf("%d %d %d %d %d %d %d %d\n", xS, yS, xE, yE, xL, yU, xR, yD);
        X=xS-xE;
        Y=yS-yE;
        yes=0;
        if(xE>=xL && xS<=xR && yE>=yD && yS<=yU)
            yes=1;
        if(yes==0 && X!=0)
        {
            m=(double)Y/X;
            y=m*(xL-xS)+yS;
            //printf("y=%.3lf ", y);
            if(y+eps<=yU && y>=yD+eps && y+eps<=yS && y>=yE+eps && x+eps<=xS && x>=xE+eps)
                yes=1;
            else
            {
                y=m*(xR-xS)+yS;
                //printf("y=%.3lf ", y);
                if(y+eps<=yU && y>=yD+eps && y+eps<=yS && y>=yE+eps && x+eps<=xS && x>=xE+eps)
                    yes=1;
            }
        }
        else if(yes==0 && Y!=0)
        {
            m=(double)X/Y;
            x=m*(yU-yS)+xS;
            //printf("x=%.3lf ", x);
            if(x+eps<=xR && x>=xL+eps && x+eps<=xS && x>=xE+eps && y+eps<=yS && y>=yE+eps)
                yes=1;
            else
            {
                x=m*(yD-yS)+xS;
                //printf("x=%.3lf#\n", x);
                if(x+eps<=xR && x>=xL+eps && x+eps<=xS && x>=xE+eps && y+eps<=yS && y>=yE+eps)
                    yes=1;
            }
        }
        if(yes==1)
            printf("T\n");
        else
            printf("F\n");

    }
    return 0;
}
