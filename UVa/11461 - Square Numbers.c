//Accepted

#include<stdio.h>
#include<math.h>
int main()
{

    int a,b,coun,sqr[100000],k,i,j,sq;
    for(i=1;i<=316;i++)
    {
        sq=i*i;
        sqr[sq]=sq;
    }
    while(scanf("%d %d",&a,&b) && (a!=0 || b!=0))
    {
        if(b==100000)
            b--;
        coun=0;
        for(j=a;j<=b;j++)
        {
            if(j==sqr[j])
               coun++;
        }
        printf("%d\n",coun);
    }
    return 0;
}
