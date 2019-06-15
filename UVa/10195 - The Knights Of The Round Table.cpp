//Accepted
#include<stdio.h>
#include<math.h>
int main()
{
    freopen("10195.txt", "r", stdin);
    double a,b,c;
    double A,s,r;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        if(a==0.0 && b==0.0 && c==0.0)
            r=0.000;
        else
        {
            s=(a+b+c)/2;
            A=sqrt(s*(s-a)*(s-b)*(s-c));
            r=(2*A)/(a+b+c);
        }
        printf("The radius of the round table is: %.3lf\n",r);
    }
    return 0;
}

