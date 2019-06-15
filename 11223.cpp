//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("11223.txt", "r", stdin);
    int t, cas, i, len, j;
    char messg[2005], code[50];
    scanf("%d\n",&t);
    //getchar();
    for(cas=1;cas<=t;cas++)
    {
        gets(messg);
        len=strlen(messg);
        if(cas>1)
            printf("\n");
        printf("Message #%d\n", cas);
        for(i=0, j=0;i<len;i++)
        {
            /*
            while(messg[i]==' ')
            {
                printf(" ");
                i++;
            }
            */

            if(messg[i]==' ' || messg[i+1]=='\0')
            {
                if(messg[i+1]=='\0' && messg[i]!=' ')
                    code[j++]=messg[i];
                code[j]='\0';
                if(strcmp(code, ".-")==0)
                    printf("A");
                else if(strcmp(code, "-...")==0)
                    printf("B");
                else if(strcmp(code, "-.-.")==0)
                    printf("C");
                else if(strcmp(code, "-..")==0)
                    printf("D");
                else if(strcmp(code, ".")==0)
                    printf("E");
                else if(strcmp(code, "..-.")==0)
                    printf("F");
                else if(strcmp(code, "--.")==0)
                    printf("G");
                else if(strcmp(code, "....")==0)
                    printf("H");
                else if(strcmp(code, "..")==0)
                    printf("I");
                else if(strcmp(code, ".---")==0)
                    printf("J");
                else if(strcmp(code, "-.-")==0)
                    printf("K");
                else if(strcmp(code, ".-..")==0)
                    printf("L");
                else if(strcmp(code, "--")==0)
                    printf("M");
                else if(strcmp(code, "-.")==0)
                    printf("N");
                else if(strcmp(code, "---")==0)
                    printf("O");
                else if(strcmp(code, ".--.")==0)
                    printf("P");
                else if(strcmp(code, "--.-")==0)
                    printf("Q");
                else if(strcmp(code, ".-.")==0)
                    printf("R");
                else if(strcmp(code, "...")==0)
                    printf("S");
                else if(strcmp(code, "-")==0)
                    printf("T");
                else if(strcmp(code, "..-")==0)
                    printf("U");
                else if(strcmp(code, "...-")==0)
                    printf("V");
                else if(strcmp(code, ".--")==0)
                    printf("W");
                else if(strcmp(code, "-..-")==0)
                    printf("X");
                else if(strcmp(code, "-.--")==0)
                    printf("Y");
                else if(strcmp(code, "--..")==0)
                    printf("Z");
                else if(strcmp(code, "-----")==0)
                    printf("0");
                else if(strcmp(code, ".----")==0)
                    printf("1");
                else if(strcmp(code, "..---")==0)
                    printf("2");
                else if(strcmp(code, "...--")==0)
                    printf("3");
                else if(strcmp(code, "....-")==0)
                    printf("4");
                else if(strcmp(code, ".....")==0)
                    printf("5");
                else if(strcmp(code, "-....")==0)
                    printf("6");
                else if(strcmp(code, "--...")==0)
                    printf("7");
                else if(strcmp(code, "---..")==0)
                    printf("8");
                else if(strcmp(code, "----.")==0)
                    printf("9");
                else if(strcmp(code, ".-.-.-")==0)
                    printf(".");
                else if(strcmp(code, "--..--")==0)
                    printf(",");
                else if(strcmp(code, "..--..")==0)
                    printf("?");
                else if(strcmp(code, ".----.")==0)
                    printf("'");
                else if(strcmp(code, "-.-.--")==0)
                    printf("!");
                else if(strcmp(code, "-..-.")==0)
                    printf("/");
                else if(strcmp(code, "-.--.")==0)
                    printf("(");
                else if(strcmp(code, "-.--.-")==0)
                    printf(")");
                else if(strcmp(code, ".-...")==0)
                    printf("&");
                else if(strcmp(code, "---...")==0)
                    printf(":");
                else if(strcmp(code, "-.-.-.")==0)
                    printf(";");
                else if(strcmp(code, "-...-")==0)
                    printf("=");
                else if(strcmp(code, ".-.-.")==0)
                    printf("+");
                else if(strcmp(code, "-....-")==0)
                    printf("-");
                else if(strcmp(code, "..--.-")==0)
                    printf("_");
                else if(strcmp(code, ".-..-.")==0)
                    printf("\"");
                else if(strcmp(code, ".--.-.")==0)
                    printf("@");
                j=0;
                while(messg[i+1]==' ')
                {
                    printf(" ");
                    i++;
                }
            }
            else code[j++]=messg[i];

        }
        printf("\n");
    }
    return 0;
}
