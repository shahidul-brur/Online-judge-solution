//Accepted

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    //freopen("10473.txt", "r", stdin);
    char num[9999];
    int change,i,j,len;
    while(scanf("%s",&num)&&num[0]!='-')
    {
        len=strlen(num);
        if(len<=2)
        {
            printf("0x%X\n",atoi(num));
        }
        else if(len>2 && num[1]!='x')
            printf("0x%X\n",atoi(num));
        else if(num[1]=='x')
        {
            change=0;
            for(i=len-1,j=0;i>1;i--,j++)
            {
                if(num[i]=='A')
                    change+=10*pow(16,j);
                else if(num[i]=='B')
                    change+=11*pow(16,j);
                else if(num[i]=='C')
                    change+=12*pow(16,j);
                else if(num[i]=='D')
                    change+=13*pow(16,j);
                else if(num[i]=='E')
                    change+=14*pow(16,j);
                else if(num[i]=='F')
                    change+=15*pow(16,j);
                else
                    change+=(num[i]-'0')*pow(16,j);
            }
            printf("%d\n",change);
        }
    }
    return 0;
}
