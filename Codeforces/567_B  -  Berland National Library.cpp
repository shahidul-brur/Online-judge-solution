/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    //freopen("b.txt", "r", stdin);
    int n, i, reg[105], maxi, current, pre;
    char sign[105], ch;
    scanf("%d", &n);
    maxi=current=0;
    for(i=0;i<n;i++)
    {
        scanf("\n%c %d", &ch, &reg[i]);
        sign[i]=ch;
        sign[i+1]='\0';
        if(ch=='+')
        {
            current++;
            if(current>maxi)
                maxi=current;
        }
        else if(ch=='-')
        {
            pre=0;
            for(int j=0;j<i;j++)
            {
                if(reg[j]==reg[i] && sign[j]=='+')
                {
                    current--;
                    pre=1;
                    break;
                }
            }
            if(pre==0)
                maxi++;
        }
    }
    printf("%d\n", maxi);
    return 0;
}
/**********************************************************
About this problem:

************************************************************/