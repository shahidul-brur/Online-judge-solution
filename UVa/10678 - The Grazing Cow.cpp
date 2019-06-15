/**********************************************************
Status:     Accepted
Problem:    UVa 10678
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
    //freopen("10678.txt", "r", stdin);
    int n, D, L;
    double a, b, area;
    cin>>n;
    while(n--)
    {
        cin>>D>>L;
        a=0.5*L;
        b=0.5*sqrtl((L*L) - (D*D));
        area=pi*a*b;
        printf("%.3lf\n", area);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

