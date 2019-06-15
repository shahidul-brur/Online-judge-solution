//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("12250.txt", "r", stdin);
    char str[25];
    int t=1;
    while(scanf("%s",&str) && strcmp(str,"#")!=0)
    {
        if(strcmp(str, "HELLO")==0)
            printf("Case %d: ENGLISH\n",t);
        else if(strcmp(str, "HOLA")==0)
            printf("Case %d: SPANISH\n",t);
         else if(strcmp(str, "HALLO")==0)
            printf("Case %d: GERMAN\n",t);
        else if(strcmp(str, "BONJOUR")==0)
            printf("Case %d: FRENCH\n",t);
        else if(strcmp(str, "CIAO")==0)
            printf("Case %d: ITALIAN\n",t);
        else if(strcmp(str, "ZDRAVSTVUJTE")==0)
            printf("Case %d: RUSSIAN\n",t);
        else
            printf("Case %d: UNKNOWN\n",t);

        t++;
    }
    return 0;
}
