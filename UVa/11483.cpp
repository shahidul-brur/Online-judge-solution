//Accepted

#include <stdio.h>
#include<string.h>
int main()
{
    freopen("11483.txt", "r", stdin);
    int n, i, c=1, len, j;
    char input[110];
    while(scanf("%d\n",&n) && n!=0)
    {
        printf("Case %d:\n",c);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
        for(i=1;i<=n;i++)
        {

            gets(input);
            len=strlen(input);
            printf("printf(\"");
            for(j=0;j<len;j++)
            {
                if(input[j]=='"' || input[j]=='\\')
                {
                    printf("\\");
                }
                printf("%c",input[j]);
            }
            printf("\\n\");");
            printf("\n");
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
        c++;
    }
    return 0;
}
