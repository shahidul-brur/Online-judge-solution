#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))

bool valid(int x1, int y1, int x2, int y2)
{
    if(x1==x2 || y1==y2)
        return true;
    else if(abs(x1-x2)==abs(y1-y2))
        return true;
    return false;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, p, q, level[102], lev, yes;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        level[i]=0;
    scanf("%d", &p);
    for(int i=0;i<p;i++)
    {
        scanf("%d", &lev);
        level[lev]=1;
    }
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        scanf("%d", &lev);
        level[lev]=1;
    }
    yes=1;
    for(int i=1;i<=n;i++)
    {
        if(level[i]==0)
        {
            yes=0;
            break;
        }
    }
    if(yes==1)
        printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");
    return 0;
}
