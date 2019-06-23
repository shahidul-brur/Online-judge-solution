#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
   freopen("498.txt", "r", stdin);
   char line1[5000], line2[5000];
   char *token;
   long long int i, j, k, co, coeff[500], v, x;
   double term, sum;
   while(gets(line1))
   {
       co=0;
       token=strtok(line1, " ");
       while(token!=NULL)
       {
            coeff[co++]=atoll(token);
            token=strtok(NULL, " ");
       }
       gets(line2);
       v=0;
       token=strtok(line2, " ");
       while(token!=NULL)
       {
           if(v>0)
                printf(" ");
            x=atoll(token);
            sum=0;
            for(i=0, j=co-1;i<co;i++, j--)
            {
                term=(double)(pow(x, j));
                sum=sum+(double)(coeff[i]*term);
            }
            printf("%.0lf", sum);
            v++;
            token=strtok(NULL, " ");
       }
       printf("\n");
   }
   return 0;
}
