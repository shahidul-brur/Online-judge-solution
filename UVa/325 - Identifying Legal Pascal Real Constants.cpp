//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
    //freopen("325.txt", "r", stdin);
    int legal, i, j, len, f, l, e, point, cntE, cntDot;
    char num[5000];
    while(gets(num))
    {
        if(num[0]=='*')
            break;
        len=strlen(num);
        if(num[0]=='\0' && len==0)
            continue;
        f=cntDot=cntE=point=0;
        l=len-1;
        e=len+5;
        legal=1;
        while(num[f]==' ')
            f++;
        while(num[l]==' ')
            l--;
        if(num[f]=='.' || num[l]=='.' || num[f]=='e' || num[f]=='E' || num[l]=='e' || num[l]=='E' || num[l]=='+' || num[l]=='-')
            legal=0;
        else
        {
            for(i=f;i<=l;i++)
            {
                if(num[i]==' ')
                {
                    legal=0;
                    break;
                }
                else if(num[i]=='e' || num[i]=='E')
                {
                    if(num[i-1]>'9' || num[i-1]<'0')
                    {
                        legal=0;
                        break;
                    }
                    else
                    {
                        e=i;
                        cntE++;
                    }
                }
                else if(num[i]=='.')
                {
                    point=1;
                    if(i>e || (num[i-1]>'9'||num[i-1]<'0'))
                    {
                        point=0;
                        legal=0;
                        break;
                    }
                    else
                        cntDot++;
                }
                else if(num[i]=='+' || num[i]=='-')
                {
                    if(i!=f && i!=e+1)
                    {
                        legal=0;
                        break;
                    }
                }
                else if((num[i]<'0' || num[i]>'9')&&(num[i]!='e' && num[i]!='E'))
                {
                    legal=0;
                    break;
                }
            }
        }
        if((point==0 && e>len) || cntDot>1 || cntE>1)
            legal=0;
        for(i=f;i<=l;i++)
            printf("%c", num[i]);
        if(legal==1)
            printf(" is legal.\n");
        else
            printf(" is illegal.\n");
    }
    return 0;
}
