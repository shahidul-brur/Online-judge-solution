//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("input190.txt", "r", stdin);
    float x1,y1,x2,y2,x3,y3,g,f,c,r,det,h,k;
    while(scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
    det=4*((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2));
    g=2*((x2*x2+y2*y2-x1*x1-y1*y1)*(y1-y3)-(x3*x3+y3*y3-x1*x1-y1*y1)*(y1-y2))/det;
    f=2*((x1-x2)*(x3*x3+y3*y3-x1*x1-y1*y1)-(x1-x3)*(x2*x2+y2*y2-x1*x1-y1*y1))/det;
    c=-(x1*x1)-(y1*y1)-2*g*x1-2*f*y1;
    r=sqrt(g*g+f*f-c);
    h=-(g);
    k=-(f);

    if(h>0 && k>0)
        printf("(x - %.3f)^2 + (y - %.3f)^2 = %.3f^2\n",h,k,r);
    else if(h<0 && k<0)
        printf("(x + %.3f)^2 + (y + %.3f)^2 = %.3f^2\n",0-h,0-k,r);
    else if(h>0 && k<0)
        printf("(x - %.3f)^2 + (y + %.3f)^2 = %.3f^2\n",h,0-k,r);
    else if(h<0 && k>0)
        printf("(x + %.3f)^2 + (y - %.3f)^2 = %.3f^2\n",0-h,k,r);
    else if(h==0 && k>0)
        printf("x^2 + (y - %.3f)^2 = %.3f^2\n",k,r);
    else if(h==0 && k==0)
        printf("x^2 + y^2 = %.3f^2\n",r);
    else if(h==0 && k<0)
        printf("x^2 + (y + %.3f)^2 = %.3f^2\n",0-k,r);
    else if(h<0 && k==0)
        printf("(x + %.3f)^2 + y^2 = %.3f^2\n",0-h,r);
    else if(h>0 && k==0)
        printf("(x - %.3f)^2 + y^2 = %.3f^2\n",h,r);

    printf("x^2 + y^2 ");
    if(g>0)
        printf("+ %.3fx ",2*g);
    else if(g<0)
        printf("- %.3fx ",0-2*g);
    if(f>0)
        printf("+ %.3fy ",2*f);
    else if(f<0)
        printf("- %.3fy ",0-2*f);
    if(c>0)
        printf("+ %.3f = 0\n",c);
    else if(c<=0)
        printf("- %.3f = 0\n",0-c);
    printf("\n");
    }
    return 0;
}
