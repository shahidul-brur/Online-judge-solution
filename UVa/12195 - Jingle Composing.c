#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("12195.txt", "r", stdin);
    int len,i,j,k,count;
    double sum;
    char str[300];
    while(scanf("%s",&str)&&str[0]!='*')
    {
        count=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            sum=0;
            for(j=i;j<len;j++)
            {
                if(str[j]=='/')
                    break;
                if(str[i]=='W')
                    sum+=1.0;
                else if(str[i]=='H')
                    sum+=0.5;
                else if(str[i]=='Q')
                    sum+=0.25;
                else if(str[i]=='E')
                    sum+=0.125;
                else if(str[i]=='S')
                    sum+=0.0625;
                else if(str[i]=='T')
                    sum+=0.03125;
                else if(str[i]=='X')
                    sum+=0.015625;
                i++;

            }
            if(sum==1.0)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
