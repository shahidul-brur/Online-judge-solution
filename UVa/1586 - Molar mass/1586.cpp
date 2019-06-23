//Accepted

#include <stdio.h>
#include <string.h>

int main()
{
    //freopen("1586.txt", "r", stdin);
    int t, i, len, C, H, N, O;
    double mass;
    char formula[100];
    scanf("%d",&t);
    while(t--)
    {
        H=N=O=C=0;
        scanf("%s",formula);
        len=strlen(formula);
        for(i=0;i<len;i++)
        {
            if(formula[i]=='H')
            {
                if(i==(len-1))
                    H++;
                else if(i==len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        H++;
                    else if(formula[i+1]>='0' && formula[i+1]<='9')
                        H+=(formula[i+1]-'0');

                }
                else if(i<len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        H++;
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]<'0' || formula[i+2]>'9'))
                        H+=(formula[i+1]-'0');
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]>='0' && formula[i+2]<='9'))
                        H = H + 10 * (formula[i+1]-'0') + (formula[i+2] - '0');
                }
            }
            else if(formula[i]=='C')
            {
                if(i==(len-1))
                    C++;
                else if(i==len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        C++;
                    else if(formula[i+1]>='0' && formula[i+1]<='9')
                        C+=(formula[i+1]-'0');
                }
                else if(i<len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        C++;
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]<'0' || formula[i+2]>'9'))
                        C+=(formula[i+1]-'0');
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]>='0' && formula[i+2]<='9'))
                        C = C + 10 * (formula[i+1]-'0') + (formula[i+2] - '0');
                }
            }
            else if(formula[i]=='O')
            {
                if(i==(len-1))
                    O++;
                else if(i==len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        O++;
                    else if(formula[i+1]>='0' && formula[i+1]<='9')
                        O+=(formula[i+1]-'0');
                }
                else if(i<len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        O++;
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]<'0' || formula[i+2]>'9'))
                        O+=(formula[i+1]-'0');
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]>='0' && formula[i+2]<='9'))
                        O = O + 10 * (formula[i+1]-'0') + (formula[i+2] - '0');
                }
            }
            else if(formula[i]=='N')
            {
                if(i==(len-1))
                    N++;
                else if(i==len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        N++;
                    else if(formula[i+1]>='0' && formula[i+1]<='9')
                        N+=(formula[i+1]-'0');
                }
                else if(i<len-2)
                {
                    if(formula[i+1]<'0' || formula[i+1]>'9')
                        N++;
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]<'0' || formula[i+2]>'9'))
                        N+=(formula[i+1]-'0');
                    else if((formula[i+1]>='0' && formula[i+1]<='9') && (formula[i+2]>='0' && formula[i+2]<='9'))
                        N = N + 10 * (formula[i+1]-'0') + (formula[i+2] - '0');
                }
            }
        }
        mass = H*1.008 + C*12.01 + O*16.00 + N*14.01;
        printf("%.3lf\n",mass);
    }
    return 0;
}
