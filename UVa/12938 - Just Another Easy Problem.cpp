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
#define sqr(a) ((a)*(a))
bool isSquare(int n)
{
    int r=sqrt(n);
    return (r*r==n);
}
bool sq[10002];
int main()
{
    for(int i=1;i<=9999;i++)
        sq[i]=isSquare(i);
    int test, cas, way, i, j, n;
    char num[6], temp[6];
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%s", num);
        way=0;
        for(i=0;i<4;i++)
        {
            if(i==0)
                j=1;
            else j=0;
            strcpy(temp, num);
            for(;j<=9;j++)
            {
                temp[i]=j+'0';
                if(num[i]!=temp[i] && sq[atoi(temp)])
                    way++;
            }
        }
        printf("Case %d: %d\n", cas, way);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

