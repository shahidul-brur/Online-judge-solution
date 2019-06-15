//Accepted

#include<stdio.h>
#include<math.h>
int main()
{
    freopen("11428.txt", "r", stdin);
    long int qube[65],i,j,n,x,y,start,flag;
    for(i=0;i<60;i++)
        qube[i]=i*i*i;
    while(scanf("%ld",&n)&&n!=0)
    {
        start=0;
        flag=0;
        while(qube[start]<n)
            start++;
        for(j=0;j<60;j++)
        {
            if(qube[j+1]-qube[j]>n)
                break;
            for(i=j+1;i<60;i++)
            {
                if(qube[i]-qube[j]>n)
                    break;
                if(qube[i]-qube[j]==n)
                {
                    x=i;
                    y=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            printf("No solution\n");
        else
            printf("%ld %ld\n",x,y);
    }
    return 0;
}
