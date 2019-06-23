//Accepted

#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("377.txt", "r", stdin);
    int t, c, triBase[14], i, j, k, carry, d, p;
    for(i=0;i<4;i++)
        triBase[i]=i;
    for(i=4;i<8;i++)
        triBase[i]=i+6;
    for(i=8;i<12;i++)
        triBase[i]=i+12;
    char num1[7], num2[7], result[10], op, ans[10], n1[10], n2[10];
    printf("COWCULATIONS OUTPUT\n");
    scanf("%d", &t);
    for(c=1;c<=t;c++)
    {
        scanf("%s\n", num1);
        scanf("%s\n", num2);
        for(i=7;i>=3;i--)
        {
            if(num1[i-3]=='V')
                d=0;
            else if(num1[i-3]=='U')
                d=1;
            else if(num1[i-3]=='C')
                d=2;
            else if(num1[i-3]=='D')
                d=3;

            n1[i]=d+'0';

            if(num2[i-3]=='V')
                d=0;
            else if(num2[i-3]=='U')
                d=1;
            else if(num2[i-3]=='C')
                d=2;
            else if(num2[i-3]=='D')
                d=3;

            n2[i]=d+'0';
        }
        for(i=0;i<=2;i++)
        {
            n1[i]='0';
            n2[i]='0';
        }
        n1[8]='\0';
        n2[8]='\0';
        for(j=1;j<=3;j++)
        {
            scanf("%c\n", &op);
            if(op=='A')
            {
                carry=0;
                for(i=7;i>=0;i--)
                {
                    p = (n1[i]-'0') + (n2[i]-'0') + carry;
                    ans[i] = triBase[p]%10 + '0';
                    carry = triBase[p]/10;
                }
                ans[8]='\0';
                strcpy(n2, ans);
            }

            else if(op=='R')
            {
                for(i=7;i>=1;i--)
                    ans[i]=n2[i-1];
                ans[0]='0';
                ans[8]='\0';

                strcpy(n2, ans);
            }
            else if(op=='L')
            {
                for(i=0;i<=6;i++)
                    ans[i]=n2[i+1];
                ans[7]='0';
                ans[8]='\0';
                strcpy(n2, ans);
            }
        }
        scanf("%s", result);
        for(i=0;i<8;i++)
        {
            if(ans[i]=='0')
                ans[i]='V';
            else if(ans[i]=='1')
                ans[i]='U';
            else if(ans[i]=='2')
                ans[i]='C';
            else if(ans[i]=='3')
                ans[i]='D';
        }
        if(strcmp(ans, result)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
