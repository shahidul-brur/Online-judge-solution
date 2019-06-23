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
    //freopen("in.txt", "r", stdin);
    int x, ans, i, j, sum;
    scanf("%d", &x);
    ans=0;
    sum=1;
    for(;x>0;)
    {
        if(sum*2>x)
        {
            x=x-sum;
            sum=1;
            ans++;
        }
        else if(sum*2==x)
        {
            sum*=2;
            x=x-sum;
            ans++;
        }
        else
        {
            sum*=2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
