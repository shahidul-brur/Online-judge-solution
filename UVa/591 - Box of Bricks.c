//Accepted
#include<stdio.h>
int main()
{
    //freopen("591.txt", "r", stdin);
    int n, b[60],i,j,sum,avg,move,c=1;
    while(scanf("%d",&n) && n!=0)
    {
        sum=move=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            sum+=b[i];
        }
        avg=sum/n;
        for(i=0;i<n;i++)
        {
            if(b[i]>avg)
                move+=(b[i]-avg);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,move);
        c++;
    }
    return 0;
}
