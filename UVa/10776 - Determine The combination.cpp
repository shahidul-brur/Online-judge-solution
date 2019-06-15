#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector <char> result;
int taken[35]={0}, used[35], n, r;
char str[35], last;
void permute()
{
    if(result.size()==r)
    {
        for(int i=0;i<r;i++)
            printf("%c", result[i]);
        printf("\n");
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(taken[j]==0)
        {
            if(result.size()!=0)
            {
                if(str[j]>=last)
                {
                    result.push_back(str[j]);
                    last=str[j];
                }
                else
                    return;
            }
            else
            {
                result.push_back(str[j]);
                last=str[j];
            }
            taken[j]=1;
            permute();
            taken[j]=0;
            result.pop_back();
        }
    }
}
int main()
{
    freopen("10776.txt", "r", stdin);
    while(scanf("%s", str)!=EOF)
    {
        scanf("%d", &r);
        n=strlen(str);
        sort(str, str+n);
        permute();
    }
    return 0;
}
