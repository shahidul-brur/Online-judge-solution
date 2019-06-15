#include<stdio.h>
#include<string.h>
int main()
{
    char str[6];
    int cas=1;
    gets(str);
    {
        if(strcmp(str,"*")==0)
            break;
        else if(strcmp(str,"Hajj")==0) printf("Hajj-e-Akbar");
        else if(strcmp(str,"Umrah")==0) printf("Hajj-e-Asghar");
    }
    return 0;
}
