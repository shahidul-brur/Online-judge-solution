//Accepted
#include<stdio.h>
int main()
{
    int i,j,k,l,a,b,c,d;
    for(i=6;i<=200;i++)
    {
        for(j=2;j<i;j++)
        {
            for(k=j+1;k<i;k++)
            {
                for(l=k+1;l<i;l++)
                {
                    a=i*i*i;
                    b=j*j*j;
                    c=k*k*k;
                    d=l*l*l;
                    if(a==(b+c+d))
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                }
            }
        }
    }
    return 0;
}
