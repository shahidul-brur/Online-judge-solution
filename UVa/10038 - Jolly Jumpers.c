//Accepted

#include<stdio.h>
int main()
{
    int n, num[3005],i,j,jolly;
    while(scanf("%d", &n)!=EOF)
    {
        jolly=0;
        for(i=1;i<=n;i++)
          scanf("%d", &num[i]);
        for(i=1;i<n;i++)
         {
            for(j=1;j<n;j++)
            {
                if(num[j]-num[j+1]==i || num[j+1]-num[j]==i)
                {
                    jolly++;
                    break;
                }

            }
         }
            if(jolly==n-1)
                printf("Jolly\n");
            else
                printf("Not jolly\n");
    }
    return 0;
}
