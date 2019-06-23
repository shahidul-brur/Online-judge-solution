#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define vector<int> vi
#define EPS 1e-4
#define INF 1000000000

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, x[6], y[6], x1, x2, y1, y2, ans, i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    if(n==1)
        cout << "-1\n";
    else
    {
        sort(x, x+n);
        sort(y, y+n);

        if(n==2 && (x[0]==x[1] || y[0]==y[1]))
            cout << "-1\n";
        else
        {
            ans = abs(x[0] - x[n-1])*abs(y[0] - y[n-1]);
            cout << ans << "\n";
        }
    }
    return 0;
}
