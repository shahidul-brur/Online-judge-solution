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
    int test, A, B, cnt;
    cin>>test;
    while(test--)
    {
        cin>>A>>B;
        cnt=0;
        while(A&(A-1))
        {
            A/=2;
            cnt++;
        }
        cnt+=abs(log(A)/log(2)-log(B)/log(2));
        printf("%d\n", cnt);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
