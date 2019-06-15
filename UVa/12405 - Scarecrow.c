//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("12405.txt", "r", stdin);
    int t,n,i,count,c;
    char str[150];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
       scanf("%d",&n);
       scanf("%s",&str);
       count=0;
       for(i=0;i<n;i+=3)
       {
           while(str[i]=='#')
           {
               i++;
           }
           if(i>=n)
            break;
           if(str[i]=='.' || str[i+1]=='.' || str[i+2]=='.')
            {
                count++;
            }
       }
       printf("Case %d: %d\n",c,count);
    }
    return 0;
}
