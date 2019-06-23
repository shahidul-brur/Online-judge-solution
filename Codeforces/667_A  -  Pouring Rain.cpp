#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double v, d, h, e, area;
    while(cin>>d>>h>>v>>e)
    {
        area = (PI * d*d)/4.0;
        if(area*e - v > 1e-4)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << area*h/(v-e*area) << "\n";
        }
    }
    return 0;
}
