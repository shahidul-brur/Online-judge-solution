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
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
int main()
{
    //freopen("c.txt", "r", stdin);
    int n, m, i, cons, j, p;
    char ch[4], str[300005], pre;
    scanf("%d %d", &n, &m);
    scanf("%s", &str);
    cons=0;
    for(i=0;i<n;i++)
    {
        if(str[i]=='.')
        {
            for(j=i+1;str[j]=='.' && j<n;j++)
                cons++;
            i=j-1;
        }
    }
    while(m--)
    {
        scanf("%d %s", &p, &ch);
        pre=str[p-1];
        str[p-1]=ch[0];
        if((pre=='.' && ch[0]!='.') || (pre!='.' && ch[0]=='.'))
        {
            if(p>1)
            {
                if(ch[0]=='.')
                {
                    if(str[p-2]=='.')
                        cons++;
                }
                else
                {
                    if(str[p-2]=='.')
                        cons--;
                }
            }
            if(p<n)
            {
                if(ch[0]=='.')
                {
                    if(str[p]=='.')
                        cons++;
                }
                else
                {
                    if(str[p]=='.')
                        cons--;
                }
            }
        }
        printf("%d\n", cons);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/