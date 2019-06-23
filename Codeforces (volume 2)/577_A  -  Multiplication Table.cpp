#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int main()
{
    int n, x, cnt, i;
    scanf("%d %d", &n, &x);
    cnt=0;
    for(i=1;i<=n;i++)
        if(x%i==0 && x/i<=n)
        cnt++;
    printf("%d\n", cnt);

    return 0;
 }